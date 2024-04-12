#include <fstream>
#include <array>

int main() {
    int num;
    auto arr = new int[100000]{};
    std::ifstream ReadFile("cavalryin.txt");
    std::ofstream WriteFile("cavalryout.txt");

    ReadFile >> num;
    while (num--) {
        int knight;
        ReadFile >> knight;
        ++arr [knight - 1];
    }

    bool can = true;
    for (int i = 1; i < 100001; ++i) {
        if (arr [i - 1] % i == 0) {
            continue;
        } else {
            can = false;
            break;
        }
    }

    WriteFile << ((can) ? "YES" : "NO");

    return 0;
}