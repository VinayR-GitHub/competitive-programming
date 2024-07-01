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
    // Extended ethene molecules always suffice.
    if (n < 6) std::cout << "-1\n";
    else if (n % 2 == 0) {
        std::cout << "1 2\n";
        std::cout << "1 3\n";
        std::cout << "1 4\n";
        std::cout << "4 5\n";
        std::cout << "4 6\n";
        for (int i = 6; i < n; ++i) {
            std::cout << i << ' ';
            std::cout << i + 1 << '\n';
        }
    } else {
        std::cout << "1 2\n";
        std::cout << "1 3\n";
        std::cout << "1 4\n";
        std::cout << "4 5\n";
        std::cout << "4 7\n";
        std::cout << "1 6\n";
        for (int i = 7; i < n; ++i) {
            std::cout << i << ' ';
            std::cout << i + 1 << '\n';
        }
    }
    // The algorithm always works for lines.
    for (int i = 1; i < n; ++i) {
        std::cout << i << ' ';
        std::cout << i + 1 << '\n';
    }
    return 0;
}