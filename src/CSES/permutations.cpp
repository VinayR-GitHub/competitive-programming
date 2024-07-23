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
    if (n == 1) {
        std::cout << '1';
    } else if (n < 4) {
        std::cout << "NO SOLUTION";
    } else {
        std::cout << '2';
        for (int i = 4; i <= n; i += 2) {
            std::cout << ' ' << i;
        }
        for (int i = 1; i <= n; i += 2) {
            std::cout << ' ' << i;
        }
    }
    return 0;
}