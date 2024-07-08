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
        int x1, x2, x3;
        std::cin >> x1 >> x2 >> x3;
        std::cout << MAX(x1, MAX(x2, x3)) - MIN(x1, MIN(x2, x3)) << '\n';
    }
    return 0;
}