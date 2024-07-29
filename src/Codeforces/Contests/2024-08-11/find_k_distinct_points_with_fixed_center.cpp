#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int t; std::cin >> t;
    while (t--) {
        int x, y, k;
        std::cin >> x >> y >> k;
        for (int i = 0; i < k - k % 2; ++i) {
            std::cout << x << ' ';
            if (i & 1) {
                std::cout << y + (i / 2) + 2;
            } else {
                std::cout << y - (i / 2) - 2;
            }
            std::cout << '\n';
        }
        if (k & 1) {
            std::cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}