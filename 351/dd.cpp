#include <iostream>
#include <vector>
using namespace std;

int H, W;

bool isValid(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

int dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y) {
    visited[x][y] = true;
    int freedom = 1; // Include the current cell

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (isValid(nx, ny) == 1 && visited[nx][ny] == false && board[nx][ny] == '.') {
            freedom += dfs(board, visited, nx, ny);
        }
    }

    return freedom;
}

int countFreedom(vector<vector<char>>& board) {
    H = board.size();
    W = board[0].size();
    int maxFreedom = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] == '.') {
                vector<vector<bool>> visited(H, vector<bool>(W, false));
                for(int i = 0; i < H; i++) {
                    for(int j = 0; j < W; j++) {
                        visited[i][j] = false;
                    }
                }
                maxFreedom = max(maxFreedom, dfs(board, visited, i, j));
                cout << "maxFreedom: " << maxFreedom << endl;
                cout << "i: " << i << " j: " << j << endl;
            }
        }
    }

    return maxFreedom;
}

int main() {
    cin >> H >> W;
    vector<vector<char>> board(H, vector<char>(W));

    // Read the board from input
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> board[i][j];
        }
    }

    // Output the result
    cout << countFreedom(board) << endl;

    return 0;
}
