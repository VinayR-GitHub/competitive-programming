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
    int a, b, c, d, e, f, g, h, i, j, k, l;
    std::cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    bool canx = MIN(d, j) > MAX(g, a);
    bool cany = MIN(e, k) > MAX(h, b);
    bool canz = MIN(f, l) > MAX(i, c);
    if (canx && cany && canz) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
    return 0;
}