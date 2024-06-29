#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    std::vector<long long> luckies;
    for (int k = 0; k < 11; ++k) {
        for (int i = 0; i < 1 << k; ++i) {
            int num4s = 0;
            int num7s = 0;
            long long num = 0LL;
            long long iter = 1LL;
            for (int j = 0; j < k; ++j) {
                if (i & 1LL << j) {
                    num += 4LL * iter;
                    ++num4s;
                } else {
                    num += 7LL * iter;
                    ++num7s;
                }
                iter *= 10LL;
            }
            if (num4s == num7s) {
                luckies.push_back(num);
            }
        }
    }
    std::sort(luckies.begin(), luckies.end());
    long long n; std::cin >> n;
    long long super = *std::lower_bound(luckies.begin(), luckies.end(), n);
    std::cout << super;
    return 0;
}