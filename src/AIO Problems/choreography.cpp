#include <fstream>
#include <array>

int main() {
    int d, t;
    std::ifstream ReadFile("dancein.txt");
    std::ofstream WriteFile("danceout.txt");

    ReadFile >> d >> t;
    auto curvals = new int[d]{};
    auto maxes = new int[d]{};
    while (t--) {
        int ai, bi;
        ReadFile >> ai >> bi;
        ++curvals [ai - 1];
        --curvals [bi - 1];
        if (curvals [ai - 1] > maxes [ai - 1]) {
            maxes [ai - 1] = curvals [ai - 1];
        }
    }

    int sum = 0;
    while (d--) {
        sum += maxes [d];
    }

    WriteFile << sum;
    
    return 0;
}