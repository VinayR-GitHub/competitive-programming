#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int n, a, b; std::cin >> n >> a >> b;
    n += a;
    int ca = 0;
    while (n > 0) {
        n -= a;
        if (n % b == 0) break;
        ++ca;
    }
    if (n % b == 0 && n >= 0) {
        std::cout << "YES\n";
        std::cout << ca << ' ' << n / b;
    } else {
        std::cout << "NO";
    }
    return 0;
}