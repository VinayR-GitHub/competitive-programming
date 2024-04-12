#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>

int main() {
    int n, m, k;
    int ch1, ch2, ch3;
    std::ifstream ReadFile("melodyin.txt");
    std::ofstream WriteFile("melodyout.txt");

    ReadFile >> n >> k;
    m = n / 3;
    auto quants1 = new int[k]{};
    auto quants2 = new int[k]{};
    auto quants3 = new int[k]{};
    while (m--) {
        int val1, val2, val3;
        ReadFile >> val1 >> val2 >> val3;
        ++quants1 [val1 - 1];
        ++quants2 [val2 - 1];
        ++quants3 [val3 - 1];
    }

    ch1 = *std::max_element(quants1, quants1 + k);
    ch2 = *std::max_element(quants2, quants2 + k);
    ch3 = *std::max_element(quants3, quants3 + k);

    WriteFile << (n - ch1 - ch2 - ch3);

    return 0;
}