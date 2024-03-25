#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

int main() {
    int d, w;
    std::unordered_map<int, int> dict;
    
    std::ifstream ReadFile("dictin.txt");
    std::ofstream WriteFile("dictout.txt");

    ReadFile >> d >> w;
    while (d--) {
        int key, val;
        ReadFile >> key >> val;
        dict [key] = val;
    }
    while (w--) {
        int item;
        ReadFile >> item;
        if (dict.find(item) == dict.end()) {
            WriteFile << "C?" << std::endl;
        } else {
            WriteFile << dict.at(item) << std::endl;
        }
    }

    ReadFile.close();
    WriteFile.close();

    return 0;
}