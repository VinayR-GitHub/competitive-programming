#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    long long n; std::cin >> n;
    int fp = -1;
    for (int i = 2; i < 2 + std::sqrt(n); ++i) {
        if (n % i == 0) {
            fp = i;
            break;
        }
    }
    if (fp == -1) {
        std::cout << n;
    } else {
        while (n % fp == 0) {
            n /= fp;
        }
        if (n == 1) {
            std::cout << fp;
        } else {
            std::cout << 1;
        }
    }
    return 0;
}