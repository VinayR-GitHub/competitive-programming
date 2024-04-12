#include <fstream>

#define DIST(a, b) (std::abs(a) + std::abs(b))

int main() {
    int k;
    int x = 0;
    int y = 0;
    std::string str;
    std::ifstream ReadFile("robotin.txt");
    std::ofstream WriteFile("robotout.txt");

    ReadFile >> k >> str;
    for (int i = 0; i < k; ++i) {
        switch (str [i]) {
            case 'E':
                ++x;
                break;
            case 'W':
                --x;
                break;
            case 'N':
                ++y;
                break;
            case 'S':
                --y;
                break;
        }
    }

    WriteFile << DIST(x, y);

    return 0;
}