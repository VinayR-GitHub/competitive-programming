#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int n; std::cin >> n;
    long long fact = 1LL;
    for (int i = 1; i < n + 1; ++i) {
        fact *= i;
        fact %= 1000000007LL;
    }
    long long pow2 = 1LL;
    for (int i = 0; i < n - 1; ++i) {
        pow2 *= 2LL;
        pow2 %= 1000000007LL;
    }
    long long res = fact - pow2;
    res %= 1000000007LL;
    res += 1000000007LL;
    res %= 1000000007LL;
    std::cout << res;
    return 0;
}