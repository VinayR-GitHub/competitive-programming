#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    long long* fib = new long long[100]{};
    fib [0] = 1LL;
    fib [1] = 1LL;
    for (int i = 2; i < 100; ++i) {
        fib [i] = fib [i - 1] + fib [i - 2];
        fib [i] %= 1000000000;
    }
    int n, m; std::cin >> n >> m;
    int* a = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
    }
    int ti, xi, vi, li, ri;
    while (m--) {
        std::cin >> ti;
        if (ti == 1) {
            std::cin >> xi >> vi;
            a [xi - 1] = vi;
        } else {
            std::cin >> li >> ri;
            long long tot = 0LL;
            for (int i = 0; i < ri - li + 1; ++i) {
                tot += 1LL * a [i + li - 1] * fib [i];
                tot %= 1000000000;
            }
            std::cout << tot << '\n';
        }
    }
    return 0;
}