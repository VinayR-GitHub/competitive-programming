#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define MIN(x, y) ((x > y) ? y : x)

int main() {
    // Reading input.
    std::string text_iter;
    std::vector<std::string> input_vec;

    std::ifstream ReadFile("bendin.txt");
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
    std::vector<std::string> first_rec = split_str(input_vec [0], ' ');
    std::vector<std::string> second_rec = split_str(input_vec [1], ' ');

    // Main program body.
    int first_area = (std::stoi(first_rec [2]) - std::stoi(first_rec [0])) * (std::stoi(first_rec [3]) - std::stoi(first_rec [1]));
    int second_area = (std::stoi(second_rec [2]) - std::stoi(second_rec [0])) * (std::stoi(second_rec [3]) - std::stoi(second_rec [1]));
    int diff_area = 0;
    if (std::stoi(first_rec [2]) <= std::stoi(second_rec [0]) || std::stoi(second_rec [2]) <= std::stoi(first_rec [0])) {
        ;
    } else if (std::stoi(first_rec [3]) <= std::stoi(second_rec [1]) || std::stoi(second_rec [3]) <= std::stoi(first_rec [1])) {
        ;
    } else {
        diff_area = MIN(MIN(std::stoi(first_rec [2]) - std::stoi(first_rec [0]), std::stoi(second_rec [2]) - std::stoi(second_rec [0])), MIN(std::abs(std::stoi(first_rec [0]) - std::stoi(second_rec [2])), std::abs(std::stoi(first_rec [2]) - std::stoi(second_rec [0])))) * MIN(MIN(std::stoi(first_rec [3]) - std::stoi(first_rec [1]), std::stoi(second_rec [3]) - std::stoi(second_rec [1])), MIN(std::abs(std::stoi(first_rec [1]) - std::stoi(second_rec [3])), std::abs(std::stoi(first_rec [3]) - std::stoi(second_rec [1]))));                     
    }
    int output = first_area + second_area - diff_area;

    // Writing output.
    std::ofstream WriteFile("bendout.txt");
    
    WriteFile << output;
    WriteFile.close();

    return 0;
}