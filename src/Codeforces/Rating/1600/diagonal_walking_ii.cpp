#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int q; std::cin >> q;
    while (q--) {
        long long ni, mi, ki;
        std::cin >> ni >> mi >> ki;
        ni = MAG(ni);
        mi = MAG(mi);
        if (ki < MAX(ni, mi)) {
            std::cout << "-1\n";
            continue;
        }
        long long res = ki;
        if (ni - mi & 1) --res;
        else if (res - MAX(ni, mi) & 1) res -= 2;
        std::cout << res << '\n';
    }
    return 0;
}