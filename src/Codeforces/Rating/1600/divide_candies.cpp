#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    long long n, m;
    std::cin >> n >> m;
    int* combos = new int[m * m]{};
    long long cachenum = 0LL;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            long long num = (i + 1LL) * (i + 1LL) + (j + 1LL) * (j + 1LL);
            if (num % m == 0) {
                combos [i * m + j] = 1;
                ++cachenum;
            }
        }
    }
    long long res = cachenum * (n / m) * (n / m);
    long long side = 0LL;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n % m; ++j) {
            side += combos [i * m + j];
        }
    }
    side *= n / m;
    side *= 2;
    res += side;
    long long corner = 0LL;
    for (int i = 0; i < n % m; ++i) {
        for (int j = 0; j < n % m; ++j) {
            corner += combos [i * m + j];
        }
    }
    res += corner;
    std::cout << res;
    return 0;
}