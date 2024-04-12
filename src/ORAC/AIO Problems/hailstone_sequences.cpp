#include <fstream>

int collatz(int n) {
    int total = 0;
    while (n != 1) {
        if (n % 2 == 1) {
            n = 3 * n + 1;
        } else {
            n >>= 1;
        }
        ++total;
    }
    return total;
}

int main() {
    std::string iter;
    std::ifstream ReadFile("hailin.txt");
    std::ofstream WriteFile("hailout.txt");

    while (std::getline(ReadFile, iter)) {
        int n = std::stoi(iter);
        if (n == 0) {
            break;
        } else {
            WriteFile << collatz(n) << std::endl;
        }
    }

    return 0;
}