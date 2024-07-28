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
    int n; std::cin >> n;
    int* items = new int[n * n]{};
    for (int i = 0; i < n * n; ++i) {
        std::cin >> items [i];
    }
    short* memorised = new short[1U << n]{};
    int* memoise = new int[1U << n]{};

    std::function<int(unsigned)> solve;
    solve = [&](unsigned val)->int {
        if (memorised [val]) {
            return memoise [val];
        }
        int num = __builtin_popcount(val);
        int res = INT_MAX;
        int count = 0;
        for (int ind = 0; ind < n; ++ind) {
            if ((val & (1U << ind)) == 0) {
                res = MIN(res, items [num * n + ind] + solve(val | (1U << ind)));
                ++count;
            }
        }
        if (res == INT_MAX) {
            res = 0;
        }
        memorised [val] = 1;
        memoise [val] = res;
        return res;
    };

    std::cout << solve(0U);
    return 0;
}