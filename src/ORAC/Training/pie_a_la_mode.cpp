#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(mode);
    int p; std::cin >> p;
    int* ic = new int[p]{};
    for (int i = 0; i < p; ++i) std::cin >> ic [i];
    std::sort(ic, ic + p);
    int cur = 1;
    int curflav = ic [0];
    int maxflav = ic [0];
    int max = 0;
    for (int i = 1; i < p; ++i) {
        if (curflav == ic [i]) ++cur;
        else {
            if (cur > max) {
                max = cur;
                maxflav = curflav;
            }
            cur = 1;
            curflav = ic [i];
        }
    }
    if (cur > max) {
        max = cur;
        maxflav = curflav;
    }

    std::cout << maxflav << ' ' << max;
    return 0;
}