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
    long long cur = 1LL;
    while (n--) {
        cur <<= 1;
        cur %= 1000000007LL;
    }
    std::cout << cur;
    return 0;
}