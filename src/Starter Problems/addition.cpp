#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    // Reading input.
    std::string text_iter;
    std::string input_str;

    std::ifstream ReadFile("addin.txt");
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
    std::vector<std::string> int_in_str = split_str(input_str, ' ');

    // Main program body.
    int out_val = std::stoi(int_in_str [0]) + std::stoi(int_in_str [1]);
    std::string output = std::to_string(out_val);

    // Writing output.
    std::ofstream WriteFile("addout.txt");
    
    WriteFile << output;
    WriteFile.close();

    return 0;
}