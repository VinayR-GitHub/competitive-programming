#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    long long n, a, b, c; std::cin >> n >> a >> b >> c;
    n %= 4;
    int k = 4 - n;
    k %= 4;
    if (k == 0) {
        std::cout << 0;
    } else if (k == 1) {
        std::cout << MIN(a, MIN(3 * c, b + c));
    } else if (k == 2) {
        std::cout << MIN(b, MIN(2 * a, 2 * c));
    } else {
        std::cout << MIN(c, MIN(3 * a, a + b));
    }
    return 0;
}