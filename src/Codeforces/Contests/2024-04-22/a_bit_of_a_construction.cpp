#include <iostream>
#include <array>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;
    while (t--) {
        int n, k; std::cin >> n >> k;
        if (n == 1) {
            std::cout << k << '\n';
            continue;
        }
        for (int i = 0; i < (n - 2); ++i) {
            std::cout << "0 ";
        }
        int* bitarr = new int[31]{};
        int num = 0;

        bitarr [0] = (int) !((k & 0b1) == 0);
        for (int i = 1; i < 31; ++i) {
            bitarr [i] = (int) !((k & (0b1 << i)) == 0);
            if (bitarr [i] && !bitarr [i - 1]) {
                num = MAX(num, i);
            }
        }
        if (!num) {
            std::cout << "0 " << k << '\n';
            continue;
        }

        bitarr [num] = 0;
        for (int i = 0; i < num; ++i) ++bitarr [i];
        ++bitarr [0];
        for (int i = 0; i < 31; ++i) {
            if (bitarr [i] > 2) {
                bitarr [i] -= 2;
                ++bitarr [i + 1];
            }
        }

        int val1 = 0, val2 = 0;
        for (int i = 0; i < 31; ++i) {
            if (bitarr [i]) {
                --bitarr [i];
                val1 += (0b1 << i);
            }
            if (bitarr [i]) {
                val2 += (0b1 << i);
            }
        }
        std::cout << val1 << ' ' << val2 << '\n';
    }

    return 0;
}