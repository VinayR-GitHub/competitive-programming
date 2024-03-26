#include <fstream>

int main() {
    int d, adic_val;
    std::ifstream ReadFile("cutein.txt");
    std::ofstream WriteFile("cuteout.txt");

    ReadFile >> d;
    while (d--) {
        int dig;
        ReadFile >> dig;
        if (dig) {
            adic_val = 0;
        } else {
            ++adic_val;
        }
    }

    WriteFile << adic_val;

    return 0;
}