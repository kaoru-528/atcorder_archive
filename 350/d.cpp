#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y) return;

        if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
        } else {
            parent[root_y] = root_x;
            if (rank[root_x] == rank[root_y]) {
                rank[root_x]++;
            }
        }
    }
};

int maxOperations(int N, int M, vector<pair<int, int>>& friendships) {
    UnionFind uf(N);
    unordered_set<int> friends_of_friends;
    int operations = 0;
    for (auto& fr : friendships) {
        int u = fr.first - 1;
        int v = fr.second - 1;
        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
        }
    }

    for (auto& fr : friendships) {
        int u = fr.first - 1;
        int v = fr.second - 1;
        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            operations++;
            friends_of_friends.insert(u);
            friends_of_friends.insert(v);
        }
    }

    for (auto& fr : friendships) {
        int u = fr.first - 1;
        int v = fr.second - 1;
        if (uf.find(u) != uf.find(v)) {
            int root_u = uf.find(u);
            int root_v = uf.find(v);
            if (friends_of_friends.count(root_u) && friends_of_friends.count(root_v)) {
                uf.unite(u, v);
                operations++;
            }
        }
    }

    return operations;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> friendships(M);
    for (int i = 0; i < M; ++i) {
        cin >> friendships[i].first >> friendships[i].second;
    }
    int max_ops = maxOperations(N, M, friendships);
    cout << "最大の操作回数: " << max_ops << endl;

    return 0;
}
