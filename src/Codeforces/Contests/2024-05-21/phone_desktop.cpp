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
    int t; std::cin >> t;

    while (t--) {
        int x, y; std::cin >> x >> y;
        int ans = 0;
        ans += (y + 1) / 2;
        int tot = x + 4 * y;
        ans = MAX(ans, tot / 15 + (tot % 15 != 0));
        std::cout << ans << '\n';
    }

    return 0;
}