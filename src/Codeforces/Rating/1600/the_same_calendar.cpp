#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int y; std::cin >> y;
    bool is_leap = y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
    int cury = y + 1;
    int ws = 0;
    for (;; ++cury) {
        bool is_this_leap = (cury - 1) % 400 == 0 || (cury - 1) % 4 == 0 && (cury - 1) % 100 != 0;
        ++ws;
        ws += is_this_leap;
        ws %= 7;
        if (ws == 0) {
            bool can_i_jump = cury % 400 == 0 || cury % 4 == 0 && cury % 100 != 0;
            if (can_i_jump == is_leap) {
                break;
            }
        }
    }
    std::cout << cury;
    return 0;
}