#include <iostream>
#include <cmath>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;
    while (t--) {
        double n, m, k; std::cin >> n >> m >> k;
        if (m == 1) {
            std::cout << "NO\n";
        } else {
            if (k < (n - std::ceil(n / m))) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
    }

    return 0;
}