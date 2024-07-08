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
    int n, k, x; std::cin >> n >> k >> x;
    int ai;
    for (int i = 0; i < k; ++i) {
        std::cin >> ai;
        std::cout << ai << ' ';
    }
    std::cout << x <<  ' ';
    for (int i = k; i < n; ++i) {
        std::cin >> ai;
        std::cout << ai << ' ';
    }
    return 0;
}