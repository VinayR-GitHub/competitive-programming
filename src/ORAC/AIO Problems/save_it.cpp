#include <iostream>
#include <array>
#include <vector>

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
    FILE(save);
    int n; std::cin >> n; long long minval = 0;
    auto c_ = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> c_ [i];
    auto mods = new int[2]{}; // 3, 4.

    for (int i = 0; i < n; ++i) {
        minval += (c_ [i] - (c_ [i] % 5));
        switch (c_ [i] % 5) {
            case 3:
                ++mods [0];
                break;
            case 4:
                ++mods [1];
                break;
            default:
                break;
        }
    }

    while (mods [0] > 0 && mods [1] > 0) {
        --mods [0]; --mods [1];
        minval += 5;
    }

    if (mods [0]) {
        while (mods [0] > 1) {
            mods [0] -= 2;
            minval += 5;
        }
        if (mods [0] == 1) {
            minval += 5;
        }
    }
    if (mods [1]) {
        while (mods [1] > 2) {
            mods [1] -= 3;
            minval += 10;
        }
        minval += (mods [1] * 5);
    }

    std::cout << minval;

    return 0;
}