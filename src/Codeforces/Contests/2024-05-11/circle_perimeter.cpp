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
        int r; std::cin >> r;
        long long r2 = static_cast<long long>(r) * static_cast<long long>(r);
        long long r12 = static_cast<long long>(1 + r) * static_cast<long long>(1 + r);
        long long count = 0;
        for (long long x = 1; x <= r; ++x) {
            long long min = r2 - x * x;
            long long max = r12 - x * x;
            long long y = MAX(0LL, static_cast<long long>(std::sqrt(min) - 1));
            while (y * y < max) {
                if (y * y >= min) ++count;
                ++y;
            }
        }
        count *= 4;
        std::cout << count << '\n';
    }

    return 0;
}