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
        std::string s;
        std::cin >> s;
        int k = s.length();
        int minx = 0;
        int maxx = 0;
        int miny = 0;
        int maxy = 0;
        int curx = 0;
        int cury = 0;
        for (int i = 0; i < k; ++i) {
            switch (s [i]) {
                case 'L':
                    --curx;
                    minx = MIN(minx, curx);
                    if (maxx - minx >= m || maxy - miny >= n) {
                        ++minx;
                        goto AFTER;
                    }
                    break;
                case 'R':
                    ++curx;
                    maxx = MAX(maxx, curx);
                    if (maxx - minx >= m || maxy - miny >= n) {
                        --maxx;
                        goto AFTER;
                    }
                    break;
                case 'D':
                    ++cury;
                    maxy = MAX(maxy, cury);
                    if (maxx - minx >= m || maxy - miny >= n) {
                        --maxy;
                        goto AFTER;
                    }
                    break;
                case 'U':
                    --cury;
                    miny = MIN(miny, cury);
                    if (maxx - minx >= m || maxy - miny >= n) {
                        ++miny;
                        goto AFTER;
                    }
                    break;
            }
        }
        AFTER:;
        std::cout << 1 - miny << ' ';
        std::cout << 1 - minx << '\n';
    }
    return 0;
}