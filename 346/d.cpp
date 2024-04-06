#include <iostream>
#include <string>

using namespace std;

// Sを無限に繰り返す関数
char getCharAt(int index) {
    string S = "wbwbwwbwbwbw";
    return S[index % S.length()];
}

int main() {
    int W, B;
    cin >> W >> B;

    bool found = false;
    for (int i = 0; i < 12; ++i) { // 12はSの長さです
        int w_count = 0, b_count = 0;
        for (int j = i; j < i + 12; ++j) {
            char current_char = getCharAt(j);
            if (current_char == 'w')
                w_count++;
            else
                b_count++;
        }
        if (w_count == W && b_count == B) {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Yes, such substring exists." << endl;
    else
        cout << "No, such substring does not exist." << endl;

    return 0;
}
