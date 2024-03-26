#include <fstream>

int main() {
    int dol, cur1, cur5, cur20, cur100;
    std::ifstream ReadFile("fashin.txt");
    std::ofstream WriteFile("fashout.txt");

    ReadFile >> dol;
    cur100 = (dol - (dol % 100)) / 100;
    cur20 = ((dol % 100) - (dol % 20)) / 20;
    cur5 = ((dol % 20) - (dol % 5)) / 5;
    cur1 = (dol % 5);

    WriteFile << cur1 + cur5 + cur20 + cur100;

    return 0;
}