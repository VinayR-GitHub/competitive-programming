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
        int x; std::cin >> x;
        int minfac;
        int prime = 2;
        while (true) {
            if (x % prime == 0) {
                minfac = prime;
                break;
            }
            ++prime;
        }
        if (prime == x) {
            std::cout << prime - 1 << '\n';
        } else {
            std::cout << x - prime << '\n';
        }
    }

    return 0;
}