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
        int* p = new int[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> p [i];
        }
        int minabs = INT_MAX;
        int* mins = new int[n]{};
        for (int i = 0; i < n; ++i) {
            minabs = MIN(minabs, p [i]);
            mins [i] = minabs;
        }
        int minval = INT_MAX;
        int luckcount = 0;
        for (int i = 0; i < n; ++i) {
            if (p [i] > mins [i] && p [i] < minval) {
                ++luckcount;
                minval = MIN(minval, p [i]);
            }
        }
        std::cout << luckcount << '\n';
    }
    return 0;
}