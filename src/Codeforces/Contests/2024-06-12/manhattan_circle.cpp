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
        int* rows = new int[n]{};
        int* cols = new int[m]{};
        char type;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> type;
                if (type == '#') {
                    ++rows [i];
                    ++cols [j];
                }
            }
        }
        int maxr = 0;
        int maxc = 0;
        int rval = 0;
        int cval = 0;
        for (int i = 0; i < n; ++i) {
            if (rows [i] > maxr) {
                maxr = rows [i];
                rval = i + 1;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (cols [i] > maxc) {
                maxc = cols [i];
                cval = i + 1;
            }
        }
        std::cout << rval << ' ';
        std::cout << cval << '\n';
    }
    return 0;
}