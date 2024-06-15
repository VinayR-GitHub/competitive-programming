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
        long long a, b, m; std::cin >> a >> b >> m;
        long long ans = (m + 1) % a != 0;
        ans += (m + 1) % b != 0;
        ans += (m + 1) / a;
        ans += (m + 1) / b;
        std::cout << ans << '\n';
    }

    return 0;
}