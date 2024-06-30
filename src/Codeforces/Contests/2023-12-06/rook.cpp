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
        char l; std::cin >> l;
        int n; std::cin >> n;
        for (int i = 1; i < 9; ++i) {
            if (i != n) {
                std::cout << l << i << '\n';
            }
        }
        for (char c = 'a'; c < 'i'; ++c) {
            if (c != l) {
                std::cout << c << n << '\n';
            }
        }
    }
    return 0;
}