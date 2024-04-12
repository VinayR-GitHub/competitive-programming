#include <fstream>

int main() {
    std::string output;
    int num;
    int total = 0;
    int log = 0;

    std::ifstream ReadFile("tripin.txt");
    std::ofstream WriteFile("tripout.txt");

    ReadFile >> num;
    while (num--) {
        int val;
        ++log;
        ReadFile >> val;
        if (val % 3 == 0) {
            ++total;
            output += std::to_string(log);
            output += " ";
        }
    }
    
    if (total) {
        WriteFile << total << std::endl << output;
    } else {
        WriteFile << "Nothing here!";
    }

    ReadFile.close();
    WriteFile.close();

    return 0;
}