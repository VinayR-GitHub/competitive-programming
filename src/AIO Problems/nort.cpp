#include <fstream>

int main() {
    int w, h;
    std::ifstream ReadFile("nortin.txt");
    std::ofstream WriteFile("nortout.txt");

    ReadFile >> w >> h;

    if (w == 1 || h == 1) {
        WriteFile << 1;
    } else if ((w * h) % 2) {
        WriteFile << ((w * h) - 1);
    } else {
        WriteFile << (w * h);
    }

    ReadFile.close();
    WriteFile.close();

    return 0;
}