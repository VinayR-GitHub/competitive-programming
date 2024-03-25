#include <iostream>
#include <fstream>
#include <vector>

int main() {
    // Reading input.
    int num;
    int capacity;
    std::vector<int> rain;
    std::string text_iter;

    std::ifstream ReadFile("rainin.txt");
    ReadFile >> num >> capacity;
    while (num--) {
        int val;
        ReadFile >> val;
        rain.push_back(val);
    }
    ReadFile.close();

    // Main program body.
    int total = 0;
    int days = 0;
    while (total < capacity) {
        total += rain [days];
        ++days;
    }

    // Writing output.
    std::ofstream WriteFile("rainout.txt");
    WriteFile << days;
    WriteFile.close();

    return 0;
}