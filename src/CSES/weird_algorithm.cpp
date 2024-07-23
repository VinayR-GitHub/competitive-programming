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
    long long n; std::cin >> n;
    std::cout << n;
    while (n != 1LL) {
        if (n & 1) {
            n *= 3LL;
            ++n;
        } else {
            n >>= 1;
        }
        std::cout << ' ' << n;
    }
}