#include <iostream>
#include <fstream>

int main() {
    // Reading input.
    std::ifstream ReadFile("countin.txt");
    int n;
    ReadFile >> n;
    ReadFile.close();

    // Writing output (main program body).
    std::ofstream WriteFile("countout.txt");
    for (int i = 1; i < n; ++i) {
        WriteFile << i << std::endl;
    }
    WriteFile << n;
    WriteFile.close();

    return 0;
}