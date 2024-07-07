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
    FILE(drop);
    int n; std::cin >> n;
    if (n == 1) {
        std::cout << '1';
        return 0;
    }
    int* a = new int[n]{};
    short* is = new short[10000000]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
        is [a [i] - 1] = i + 1;
    }
    int maxnum = 2;
    int* checked = new int[n * n]{};
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (checked [i * n + j]) continue;
            int vertices = 2;
            checked [i * n + j] = 1;
            int diff = a [j] - a [i];
            int cur = a [j] + diff;
            while (cur <= a [n - 1]) {
                if (is [cur - 1]) {
                    ++vertices;
                    checked [(is [cur - diff - 1] - 1) * n + is [cur - 1] - 1] = 1;
                } else {
                    break;
                }
                cur += diff;
            }
            maxnum = MAX(maxnum, vertices);
        }
    }
    std::cout << maxnum;
    return 0;
}