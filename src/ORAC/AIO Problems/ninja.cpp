#include <fstream>
#include <cmath>

int main() {
    double n, k;

    std::ifstream ReadFile("ninjain.txt");
    std::ofstream WriteFile("ninjaout.txt");

    ReadFile >> n >> k;

    int output = n - std::ceil(n / (k + 1));

    WriteFile << output;

    ReadFile.close();
    WriteFile.close();

    return 0;
}