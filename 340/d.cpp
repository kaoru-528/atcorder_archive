
#include <iostream>
#include <vector>
void generateCombinations(std::vector<std::string>& combinations, std::string current, int length) {
    if (length == 0) {
        combinations.push_back(current);
        return;
    }

    generateCombinations(combinations, current + '0', length - 1);
    generateCombinations(combinations, current + '1', length - 1);
}

int main() {
    int length;
    std::cout << "組み合わせの長さを入力してください: ";
    std::cin >> length;

    std::vector<std::string> combinations;
    generateCombinations(combinations, "", length);

    // 組み合わせを表示
    std::cout << "生成された組み合わせ:" << std::endl;
    for (const std::string& combination : combinations) {
        std::cout << combination << std::endl;
    }

    return 0;
}