#include <iostream>
#include <array>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(inv);
    int r, c; std::cin >> r >> c;
    char* map = new char[r * c]{};
    for (int i = 0; i < (r * c); ++i) {
        std::cin >> map [i];
    }
    int* nums = new int[26]{}; int* is_linked = new int[576]{};
    for (int j = 0; j < r; ++j) {
        bool top = j == 0; bool bottom = j == (r - 1);
        for (int i = 0; i < c; ++i) {
            bool left = i == 0; bool right = i == (c - 1);
            int cur = (int) map [j * c + i] - 97;
            if (!top) {
                int block = (int) map [(j - 1) * c + i] - 97;
                if (block != cur) {
                    if (!is_linked [cur * 26 + block]) {
                        ++is_linked [cur * 26 + block]; ++nums [cur];
                    }
                }
            }
            if (!bottom) {
                int block = (int) map [(j + 1) * c + i] - 97;
                if (block != cur) {
                    if (!is_linked [cur * 26 + block]) {
                        ++is_linked [cur * 26 + block]; ++nums [cur];
                    }
                }
            }
            if (!left) {
                int block = (int) map [j * c + i - 1] - 97;
                if (block != cur) {
                    if (!is_linked [cur * 26 + block]) {
                        ++is_linked [cur * 26 + block]; ++nums [cur];
                    }
                }
            }
            if (!right) {
                int block = (int) map [j * c + i + 1] - 97;
                if (block != cur) {
                    if (!is_linked [cur * 26 + block]) {
                        ++is_linked [cur * 26 + block]; ++nums [cur];
                    }
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < 26; ++i) {
        max = MAX(max, nums [i]);
    }

    std::cout << max;
    
    return 0;
}