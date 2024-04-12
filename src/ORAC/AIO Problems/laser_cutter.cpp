#include <iostream>
#include <array>
#include <vector>
 
#define MIN std::min
#define MAX std::max
#define PAIR std::make_pair
#define FILE(id) \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)
 
int main() {
    int n;
    FILE(laser);
 
    std::cin >> n;
    std::vector<int> a_, b_;
 
    std::pair<int, int> the_coord = PAIR(0, 0);
    for (int ins = 0; ins < (2 * n); ++ins) {
        char cur_char;
        std::cin >> cur_char;
        
        switch (cur_char) {
            case 'D':
                ++the_coord.second;
                break;
            case 'R':
                a_.push_back(the_coord.second);
                ++the_coord.first;
                break;
        }
     }
 
    the_coord = PAIR(0, 0);
    for (int ins = 0; ins < (2 * n); ++ins) {
        char cur_char;
        std::cin >> cur_char;
        
        switch (cur_char) {
            case 'D':
                ++the_coord.second;
                break;
            case 'R':
                b_.push_back(the_coord.second);
                ++the_coord.first;
                break;
        }
    }

    a_.push_back(n);
    b_.push_back(n);
 
    int max_width = 1;
 
    for (int x_val = 0; x_val < n - max_width; ++x_val) {
        while (true) {
            if (a_ [x_val] - b_ [x_val + max_width] <= max_width) {
                break;
            }
            ++max_width;
        }
    }
 
    std::cout << max_width;
 
    return 0;
}