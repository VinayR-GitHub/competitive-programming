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
        int n; std::cin >> n;
        int* a = new int[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
        }
        std::vector<int> difflocs;
        for (int i = 0; i < n - 1; ++i) {
            if (a [i] != a [i + 1]) {
                difflocs.push_back(i + 1);
            }
        }
        int q; std::cin >> q;
        int li, ri;
        while (q--) {
            std::cin >> li >> ri;
            auto iter = std::lower_bound(difflocs.begin(), difflocs.end(), li);
            if (iter == difflocs.end()) {
                std::cout << "-1 -1\n";
            } else {
                int bestloc = *iter;
                if (bestloc >= ri) {
                    std::cout << "-1 -1\n";
                } else {
                    std::cout << bestloc << ' ' << bestloc + 1 << '\n';
                }
            }
        }
    }
    return 0;
}