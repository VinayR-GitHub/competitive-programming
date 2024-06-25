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
        int* w = new int[n]{};
        for (int i = 0; i < n; ++i) std::cin >> w [i];
        int curl = 0;
        int curr = 0;
        int liter = 0;
        int riter = n - 1;
        int max = 0;
        while (liter < riter + 2) {
            if (curl == curr) {
                max = n + liter - riter - 1;
                curl += w [liter];
                ++liter;
            } else if (curl > curr) {
                curr += w [riter];
                --riter;
            } else if (curl < curr) {
                curl += w [liter];
                ++liter;
            }
        }

        std::cout << max << '\n';
    }

    return 0;
}