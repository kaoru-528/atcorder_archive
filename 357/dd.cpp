#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_carpet(int K) {
    if (K == 0) {
        cout << "B" << endl; // レベル0の場合、黒いマス1つ
        return;
    }

    // 中央のブロックを白く
    vector<string> carpet(3 << K, string(3 << K, 'W'));

    // レベルK-1のカーペットを埋める
    for (int i = 0; i < (3 << (K - 1)); ++i) {
        for (int j = 0; j < (3 << (K - 1)); ++j) {
            carpet[i][j] = 'B';
        }
    }

    // 出力
    for (int i = 0; i < (3 << K); ++i) {
        cout << carpet[i] << endl;
    }
}

int main() {
    int N;
    cin >> N;
    print_carpet(N);
    return 0;
}
