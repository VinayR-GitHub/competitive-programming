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
        int n; std::cin >> n;
        int* p = new int[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> p [i];
        }
        for (int i = 0; i < n; ++i) {
            std::cout << p [(i + 1) % n] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}