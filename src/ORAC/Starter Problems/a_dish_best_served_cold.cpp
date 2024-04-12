#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

int main() {
    // Reading input.
    int num;
    std::vector<int> terms;
    std::string text_iter;
    
    std::ifstream ReadFile("dishin.txt");
    while (std::getline(ReadFile, text_iter)) {
        terms.push_back(std::stoi(text_iter));
    }
    ReadFile.close();

    num = terms [0];
    terms.erase(terms.begin());

    // Main program body.
    int total = 0;
    int min = terms [0];
    int max = 0;
    for (auto& item : terms) {
        total += item;
        if (min > item) {
            min = item;
        }
        if (max < item) {
            max = item;
        }
    }

    // Writing output.
    std::ofstream WriteFile("dishout.txt");
    WriteFile << min << " " << max << " " << std::floor(total / num);
    WriteFile.close();

    return 0;
}