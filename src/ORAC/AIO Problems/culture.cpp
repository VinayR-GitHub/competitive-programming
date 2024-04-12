#include <fstream>

int main() {
    int b, d = 0;
    std::ifstream ReadFile("cultin.txt");
    std::ofstream WriteFile("cultout.txt");

    ReadFile >> b;
    while (b % 2 == 0) {
        b >>= 1;
        ++d;
    }

    WriteFile << b << " " << d;

    ReadFile.close();
    WriteFile.close();

    return 0;
}