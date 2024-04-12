#include <fstream>

int main() {
    int l, x, y;

    std::ifstream ReadFile("piratein.txt");
    std::ofstream WriteFile("pirateout.txt");

    ReadFile >> l;
    ReadFile >> x;
    ReadFile >> y;

    if ((x + y) <= l) {
        WriteFile << (x + y);
    } else {
        WriteFile << ((2 * l) - x - y);
    }

    ReadFile.close();
    WriteFile.close();

    return 0;
}