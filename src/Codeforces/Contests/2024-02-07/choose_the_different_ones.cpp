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
        int n, m, k;
        std::cin >> n >> m >> k;
        int* a = new int[n]{};
        int* b = new int[m]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
        }
        for (int i = 0; i < m; ++i) {
            std::cin >> b [i];
        }
        std::pair<short, short>* is_available = new std::pair<short, short>[k]{};
        for (int i = 0; i < n; ++i) {
            if (a [i] <= k) {
                is_available [a [i] - 1].first = 1;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (b [i] <= k) {
                is_available [b [i] - 1].second = 1;
            }
        }
        bool can = true;
        int onlya = 0;
        int onlyb = 0;
        int boths = 0;
        for (int i = 0; i < k; ++i) {
            if (!is_available [i].first && !is_available [i].second) {
                can = false;
                break;
            }
            if (is_available [i].first && is_available [i].second) {
                ++boths;
            } else if (is_available [i].first) {
                ++onlya;
            } else {
                ++onlyb;
            }
        }
        if (!can) {
            std::cout << "no\n";
        } else {
            k >>= 1;
            if (onlya + boths >= k && onlyb + boths >= k) {
                std::cout << "yes\n";
            } else {
                std::cout << "no\n";
            }
        }
    }
    return 0;
}