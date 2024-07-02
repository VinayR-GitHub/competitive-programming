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
        int n, p; std::cin >> n >> p;
        for (int i = 0; i < 2 * n + p; ++i) {
            int j = i % n;
            int n1 = j + i / n + 1;
            n1 %= n;
            std::cout << j + 1 << ' ';
            std::cout << n1 + 1 << '\n';
        }
    }
    return 0;
}