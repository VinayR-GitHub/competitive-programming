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
        int a, b, c;
        std::cin >> a >> b >> c;
        int x = MIN(a, MIN(b, c));
        int z = MAX(a, MAX(b, c));
        int y = a + b + c - x - z;
        if (y % x || z % x) {
            std::cout << "no\n";
            continue;
        }
        if (y / x + z / x > 5) {
            std::cout << "no\n";
        } else {
            std::cout << "yes\n";
        }
    }
    return 0;
}