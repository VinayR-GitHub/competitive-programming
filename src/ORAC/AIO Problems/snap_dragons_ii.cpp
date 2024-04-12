#include <fstream>

int main() {
    int r, c, rr, rc, sr, sc;

    std::ifstream ReadFile("snapin.txt");
    std::ofstream WriteFile("snapout.txt");

    ReadFile >> r >> c >> rr >> rc >> sr >> sc;

    if ((rr + rc - sr - sc) % 2) {
        // Rose can win.
        WriteFile << "ROSE";
    } else {
        // Scarlet can win.
        WriteFile << "SCARLET";
    }

    return 0;
}