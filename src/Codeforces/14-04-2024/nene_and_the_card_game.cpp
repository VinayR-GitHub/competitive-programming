#include <iostream>
#include <array>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;

    while (t--) {
        int n; std::cin >> n;
        int* is_there = new int[n]{};
        int dups = 0;
        for (int i = 0; i < n; ++i) {
            int temp; std::cin >> temp;
            if (is_there [temp - 1]) {
                ++dups;
            } else {
                ++is_there [temp - 1];
            }
        }

        std::cout << dups << '\n';
    }

    return 0;
}