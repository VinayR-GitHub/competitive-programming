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
        long long n, a, b; std::cin >> n >> a >> b;
        long long max = a * n;
        if (b > a) {
            long long upto = MIN(b - a, n);
            max += (b - a + 1) * upto;
            max -= (upto * (upto + 1)) / 2;
        }
        std::cout << max << '\n';
    }

    return 0;
}