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
        int* a = new int[n]{};
        int* b = new int[n]{};
        int* c = new int[n]{};
        int* d = new int[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
            c [i] = a [i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b [i];
            d [i] = b [i];
        }
        std::sort(c, c + n);
        std::sort(d, d + n);
        bool can = true;
        for (int i = 0; i < n; ++i) {
            if (c [i] != d [i]) {
                can = false;
                break;
            }
        }
        if (!can) {
            std::cout << "no\n";
            continue;
        }
        std::unordered_map<int, int> locs;
        for (int i = 0; i < n; ++i) {
            locs [b [i]] = i;
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (a [i] != b [i]) {
                ++count;
                std::swap(b [i], b [locs [a [i]]]);
                locs [b [locs [a [i]]]] = locs [a [i]];
                locs [a [i]] = i;
            }
        }
        if (count & 1) {
            std::cout << "no\n";
        } else {
            std::cout << "yes\n";
        }
    }
    return 0;
}