#include <fstream>
#include <cmath>

int main() {
    double n, m, k;

    std::ifstream ReadFile("streetin.txt");
    std::ofstream WriteFile("streetout.txt");

    ReadFile >> n >> k;
    m = n - k;

    WriteFile << (int) std::ceil(m / (k + 1));

    return 0;
}