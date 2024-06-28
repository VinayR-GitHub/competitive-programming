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
    int* is_good = new int[19683]{};
    for (int i = 1; i < 19684; ++i) {
        int k = i;
        while (true) {
            if (k % 3 == 0 && k) k /= 3;
            else if (k % 3 == 1 && k) k /= 3;
            else break;
        }
        if (!k) is_good [i - 1] = 1;
    }
    while (q--) {
        int n; std::cin >> n;
        for (int i = n;; ++i) {
            if (is_good [i - 1]) {
                std::cout << i << '\n';
                goto END;
            }
        }
        END:;
    }
    return 0;
}