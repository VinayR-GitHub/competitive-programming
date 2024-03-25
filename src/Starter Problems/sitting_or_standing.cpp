#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    // Reading input.
    std::string text_iter;
    std::vector<std::string> input_vec;

    std::ifstream ReadFile("sitin.txt");
    while (std::getline(ReadFile, text_iter)) {
        input_vec.push_back(text_iter);
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
    std::vector<std::string> space_sep = split_str(input_vec [0], ' ');

    int r = std::stoi(space_sep [0]);
    int s = std::stoi(space_sep [1]);
    int tickets = std::stoi(input_vec [1]);

    // Main program body.
    int sitting;
    int standing;

    if (tickets <= (r * s)) {
        sitting = tickets;
        standing = 0;
    } else {
        sitting = r * s;
        standing = tickets - sitting;
    }

    // Writing output.
    std::ofstream WriteFile("sitout.txt");

    WriteFile << sitting << " " << standing;
    WriteFile.close();

    return 0;
}