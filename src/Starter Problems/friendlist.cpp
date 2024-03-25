#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    auto people = new int [1001] {};
    int pop;

    std::ifstream ReadFile("listin.txt");
    std::ofstream WriteFile("listout.txt");

    ReadFile >> pop;
    while (pop--) {
        int f1, f2;
        ReadFile >> f1 >> f2;
        ++people [f1];
        ++people [f2];
    }

    int el = *std::max_element(people, people + 1001);

    std::vector<int> good_kids;
    for (int i = 0; i < 1001; ++i) {
        if (people [i] == el) {
            good_kids.push_back(i);
        }
    }

    for (auto& child : good_kids) {
        WriteFile << child << std::endl;
    }
    
    ReadFile.close();
    WriteFile.close();
    
    return 0;
}