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
        std::cout << MIN(x, y) << ' ' << MAX(x, y) << '\n';
    }

    return 0;
}