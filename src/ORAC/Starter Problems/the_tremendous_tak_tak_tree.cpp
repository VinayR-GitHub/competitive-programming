#include <iostream>
#include <fstream>

int main() {
    // Reading input.
    std::ifstream ReadFile("taktakin.txt");
    int n;
    ReadFile >> n;
    ReadFile.close();
    
    // Main program body.
    int num = 0;
    while ((n - 1) % 11) {
        ++num;
        n *= 2;
    }

    // Writing output.
    std::ofstream WriteFile("taktakout.txt");
    WriteFile << num << " " << n;
    WriteFile.close();

    return 0;
}