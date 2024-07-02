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
        int n; std::cin >> n;
        int* a = new int[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
        }
        std::sort(a, a + n);
        if (a [n - 1] > a [n - 2] + 1) {
            std::cout << "0\n";
            continue;
        }
        if (a [n - 1] == a [n - 2]) {
            long long res = 1LL;
            for (int i = 2; i <= n; ++i) {
                res *= i;
                res %= 998244353;
            }
            std::cout << res << '\n';
            continue;
        }
        int iter = std::lower_bound(a, a + n, a [n - 2]) - a;
        int num = n - iter - 1;
        long long res = 1LL;
        for (int i = 2; i <= num; ++i) {
            res *= i;
            res %= 998244353;
        }
        res *= num;
        res %= 998244353;
        for (int i = num + 2; i <= n; ++i) {
            res *= i;
            res %= 998244353;
        }
        std::cout << res << '\n';
    }
    return 0;
}