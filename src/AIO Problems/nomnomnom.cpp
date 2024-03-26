#include <fstream>

int main() {
    int n;
    int h = 0;
    int nom = 0;
    int tot = 0;
    std::ifstream ReadFile("nomin.txt");
    std::ofstream WriteFile("nomout.txt");

    ReadFile >> n;
    while (n--) {
        int fod;
        ReadFile >> fod;
        tot += fod;
        if (tot >= nom) {
            nom = tot;
            tot = 0;
            ++h;
        }
    }

    WriteFile << h;

    return 0;
}