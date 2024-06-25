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
        int p1, p2, p3; std::cin >> p1 >> p2 >> p3;
        if (p1 + p2 + p3 & 1) {
            std::cout << "-1\n";
            continue;
        }
        int ans = MIN((p1 + p2 + p3) >> 1, p1 + p2 + p3 - MAX(p1, MAX(p2, p3)));
        std::cout << ans << '\n';
    }

    return 0;
}