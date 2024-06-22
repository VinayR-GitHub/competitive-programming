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
        long long l, r; std::cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < 60; ++i) {
            if (r & (1LL << i)) {
                ans = MAX(ans, i);
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}