#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int l, d, v, g, r;
    std::cin >> l >> d >> v >> g >> r;
    int firsttime = d / v;
    if (firsttime % (r + g) < g) {
        long double res = l;
        res /= static_cast<long double>(v);
        std::cout << std::fixed << std::setprecision(6) << res;
    } else {
        int val = 1 + firsttime / (r + g);
        long double res = val * v * (r + g) + l - d;
        res /= static_cast<long double>(v);
        std::cout << std::fixed << std::setprecision(6) << res;
    }
    return 0;
}