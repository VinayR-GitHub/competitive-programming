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
    int n, k, m, t;
    std::cin >> n >> k >> m >> t;
    int ti, li;
    while (t--) {
        std::cin >> ti >> li;
        if (ti) {
            ++n;
            if (li <= k) {
                ++k;
            }
        } else {
            if (li >= k) {
                n = li;
            } else {
                n -= li;
                k -= li;
            }
        }
        std::cout << n << ' ';
        std::cout << k << '\n';
    }
    return 0;
}