#include <fstream>

int main() {
    int num, minx, miny, maxx, maxy;
    std::ifstream ReadFile("artin.txt");
    std::ofstream WriteFile("artout.txt");

    minx = 10001;
    miny = 10001;
    maxx = 0;
    maxy = 0;

    ReadFile >> num;
    while (num--) {
        int xi, yi;
        ReadFile >> xi >> yi;
        if (xi < minx) {
            minx = xi;
        }
        if (xi > maxx) {
            maxx = xi;
        }
        if (yi < miny) {
            miny = yi;
        }
        if (yi > maxy) {
            maxy = yi;
        }
    }

    WriteFile << (maxx - minx) * (maxy - miny);

    return 0;
}