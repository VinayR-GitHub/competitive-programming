#include <bits/stdc++.h>
 
#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);
 
int main() {
    int t; std::cin >> t;
    while (t--) {
        long long n, m; std::cin >> n >> m;
        if (!m) {
            std::cout << n << '\n';
            continue;
        }
        long long xorval1 = n ^ (n + m);
        long long xorval2 = n ^ MAX(0LL, n - m);
        long long xorval = xorval1 | xorval2;
        int max = 0;
        for (int i = 0; i < 60; ++i) {
            if (xorval & (1LL << i)) {
                max = MAX(max, i);
            }
        }
        ++max;
        int num = (1LL << max) - 1;
        int ans = n - (n & num) + num;
        std::cout << ans << '\n';
    }
 
    return 0;
}