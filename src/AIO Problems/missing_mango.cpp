#include <fstream>

int main() {
    int ix, cx, id, cd;

    std::ifstream ReadFile("manin.txt");
    std::ofstream WriteFile("manout.txt");

    ReadFile >> ix >> cx >> id >> cd;

    int i1 = ix - id;
    int i2 = ix + id;
    int c1 = cx - cd;
    int c2 = cx + cd;

    if (i1 == c1 || i1 == c2) {
        WriteFile << i1;
    } else if (i2 == c1 || i2 == c2) {
        WriteFile << i2;
    }

    return 0;
}