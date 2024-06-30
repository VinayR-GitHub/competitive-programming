#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    bool hor = a * d > b * c;
    int p = 0;
    int q = 0;
    if (hor) {
        p = a * d - b * c;
        q = a * d;
    } else {
        p = b * c - a * d;
        q = b * c;
    }
    int div = std::gcd(p, q);
    p /= div;
    q /= div;
    std::cout << p << '/' << q;
    return 0;
}