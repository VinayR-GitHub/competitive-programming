#include <iostream>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;
    while (t--) {
        int n, a, b; std::cin >> n >> a >> b;
        std::cout << MIN((b * (n / 2)) + a * (n & 0b1), a * n) << '\n';
    }

    return 0;
}