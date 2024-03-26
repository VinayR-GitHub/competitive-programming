#include <fstream>

int main() {
    int num;
    int min = 1000000001;
    int max = 0;
    std::ifstream ReadFile("ladyin.txt");
    std::ofstream WriteFile("ladyout.txt");

    ReadFile >> num;
    while (num--) {
        int loc;
        ReadFile >> loc;
        if (loc < min) {
            min = loc;
        }
        if (loc > max) {
            max = loc;
        }
    }

    WriteFile << (max - min + 1);

    return 0;
}