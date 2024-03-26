#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    int n, p;
    int cur = 0;
    int sol = 0;
    int num = 1;
    std::ifstream ReadFile("genin.txt");
    std::ofstream WriteFile("genout.txt");

    ReadFile >> n >> p;
    auto solves = new int[n]{};
    while (true) {
        solves [cur] += num;
        sol += num;
        if (sol >= p) {
            solves [cur] -= (sol - p);
            break;
        }
        ++num;
        ++cur;
        if (cur == n) {
            cur = 0;
        }
    }

    WriteFile << (1 + std::distance(solves, std::max_element(solves, solves + n))) << " " << *std::max_element(solves, solves + n);

    return 0;
}