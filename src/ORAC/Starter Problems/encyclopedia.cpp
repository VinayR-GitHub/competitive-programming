#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream ReadFile("encyin.txt");
    std::ofstream WriteFile("encyout.txt");
    std::vector<int> words_per_page;

    int n, q;
    ReadFile >> n >> q;
    while (n--) {
        int count;
        ReadFile >> count;
        words_per_page.push_back(count);
    }
    while (q--) {
        int num;
        ReadFile >> num;
        WriteFile << words_per_page [num - 1] << std::endl;
    }

    ReadFile.close();
    WriteFile.close();

    return 0;
}