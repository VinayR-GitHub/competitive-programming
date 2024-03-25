#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    // Reading input.
    std::string text_iter;
    std::string input_str;

    std::ifstream ReadFile("mixin.txt");
    while (std::getline(ReadFile, text_iter)) {
        input_str += text_iter;
    }
    ReadFile.close();

    auto split_str = [] (std::string str, char split_char) -> std::vector<std::string> {
        std::stringstream stream(str);
        std::vector<std::string> main_vec;
        std::string tok;
        while (std::getline(stream, tok, split_char)) {
            main_vec.push_back(tok);
        }
        return main_vec;
    };
    std::vector<std::string> numer_denom = split_str(input_str, ' ');

    int n = std::stoi(numer_denom [0]);
    int d = std::stoi(numer_denom [1]);

    // Main program body.
    int b = n % d;
    int a = (n - b) / d;

    // Writing output.
    std::ofstream WriteFile("mixout.txt");

    if (b != 0) {
        WriteFile << a << " " << b << "/" << d;
    } else {
        WriteFile << a;
    }
    WriteFile.close();

    return 0;
}