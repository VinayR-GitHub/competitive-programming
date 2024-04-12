#include <fstream>

int main() {
    int flowers;

    std::ifstream ReadFile("vasesin.txt");
    std::ofstream WriteFile("vasesout.txt");

    ReadFile >> flowers;

    if (flowers < 6) {
        WriteFile << "0 0 0";
    } else {
        WriteFile << "1 2 " << (flowers - 3);
    }

    ReadFile.close();
    WriteFile.close();

    return 0;
}