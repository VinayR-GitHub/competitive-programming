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
        int n, k; std::cin >> n >> k;
        long long* a = new long long[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
        }
        int* kloc = new int[64]{};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 64; ++j) {
                int rem = a [i] % k;
                kloc [j] += rem;
                a [i] /= k;
            }
        }
        bool can = true;
        for (int i = 0; i < 64; ++i) {
            if (kloc [i] > 1) {
                can = false;
                break;
            }
        }
        if (can) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
    return 0;
}