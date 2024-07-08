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
        int n, m; std::cin >> n >> m;
        int* a = new int[n * m]{};
        for (int i = 0; i < n * m; ++i) {
            std::cin >> a [i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int newval = 0;
                bool is = false;
                if (i) {
                    if (a [(i - 1) * m + j] > a [i * m + j]) {
                        is = true;
                    }
                    newval = MAX(newval, a [(i - 1) * m + j]);
                }
                if (i != n - 1) {
                    if (a [(i + 1) * m + j] > a [i * m + j]) {
                        is = true;
                    }
                    newval = MAX(newval, a [(i + 1) * m + j]);
                }
                if (j) {
                    if (a [i * m + j - 1] > a [i * m + j]) {
                        is = true;
                    }
                    newval = MAX(newval, a [i * m + j - 1]);
                }
                if (j != m - 1) {
                    if (a [i * m + j + 1] > a [i * m + j]) {
                        is = true;
                    }
                    newval = MAX(newval, a [i * m + j + 1]);
                }
                if (!is) {
                    a [i * m + j] = newval;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << a [i * m + j] << ' ';
            }
            std::cout << '\n';
        }
    }
    return 0;
}