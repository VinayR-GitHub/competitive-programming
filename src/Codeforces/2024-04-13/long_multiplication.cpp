#include <iostream>
#include <string>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    std::string t_;
    std::getline(std::cin, t_);
    int t = std::stoi(t_);
    while (t--) {
        std::string x_val_str, y_val_str;
        int x_out_str[100], y_out_str[100];
        std::getline(std::cin, x_val_str);
        std::getline(std::cin, y_val_str);
        int max = x_val_str.length();
        bool ascending = true;
        for (int i = 0; i < x_val_str.length(); ++i) {
            if ((int) x_val_str [i] == 0) {
                max = i - 1;
                break;
            }
            if ((int) x_val_str [i] == (int) y_val_str [i]) {
                x_out_str [i] = (int) x_val_str [i] - 48;
                y_out_str [i] = (int) y_val_str [i] - 48;
            } else if (ascending) {
                ascending = false;
                x_out_str [i] = MAX((int) x_val_str [i], (int) y_val_str [i]) - 48;
                y_out_str [i] = MIN((int) x_val_str [i], (int) y_val_str [i]) - 48;
            } else {
                x_out_str [i] = MIN((int) x_val_str [i], (int) y_val_str [i]) - 48;
                y_out_str [i] = MAX((int) x_val_str [i], (int) y_val_str [i]) - 48;
            }
        }

        for (int i = 0; i < max; ++i) std::cout << x_out_str [i]; std::cout << '\n';
        for (int i = 0; i < max; ++i) std::cout << y_out_str [i]; std::cout << '\n';
    }

    return 0;
}