#include <fstream>
#include <array>

int main() {
    int r, s;
    int pairs = 0;
    std::ifstream ReadFile("snapin.txt");
    std::ofstream WriteFile("snapout.txt");

    ReadFile >> r >> s;
    auto r_vals =  new int[10000]{};
    while (r--) {
        int val;
        ReadFile >> val;
        ++r_vals [val - 1];
    }
    while (s--) {
        int val;
        ReadFile >> val;
        pairs += r_vals [val - 1];
    }

    WriteFile << pairs;

    return 0;
}