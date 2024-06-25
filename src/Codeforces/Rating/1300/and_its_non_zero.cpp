#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    ACCEL();

    int* precompute = new int[3800000]{};
    for (int bit = 0; bit < 19; ++bit) {
        int mask = 1 << bit;
        int running = 0;
        for (int i = 0; i < 200000; ++i) {
            running += ((i + 1) & mask) == 0;
            precompute [bit * 200000 + i] = running;
        }
    }

    int t; std::cin >> t;
    while (t--) {
        int l, r; std::cin >> l >> r;
        int min = INT_MAX;
        for (int i = 0; i < 19; ++i) {
            int ans = precompute [i * 200000 + r - 1] - precompute [i * 200000 + l - 1];
            ans += (l & 1 << i) == 0;
            min = MIN(min, ans);
        }

        std::cout << min << '\n';
    }

    return 0;
}