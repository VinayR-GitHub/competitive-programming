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
        int* b = new int[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> b [i];
        }
        bool can = true;
        long long iter = n - 1;
        int* poss = new int[n]{};
        for (int i = 0; i < k; ++i) {
            if (poss [iter]) {
                break;
            }
            poss [iter] = 1;
            if (b [iter] > n) {
                can = false;
                break;
            }
            iter -= b [iter];
            iter %= n;
            iter += n;
            iter %= n;
        }
        if (can) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
    return 0;
}