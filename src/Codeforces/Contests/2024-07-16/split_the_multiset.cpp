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
        int n, k; std::cin >> n >> k;
        int res = (n - 1) / (k - 1);
        res += MIN((n - 1) % (k - 1), 1);
        std::cout << res << '\n';
    }
    return 0;
}