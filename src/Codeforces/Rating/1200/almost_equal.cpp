#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int n; std::cin >> n;

    if (n % 2 == 0) {
        std::cout << "NO";
    } else {
        std::cout << "YES\n";
        int* sol = new int[2 * n]{};
        for (int i = 0; i < n; ++i) {
            sol [2 * i + 1] = 1;
        }
        for (int i = 0; i < n; ++i) {
            sol [i] += 2 * i + 1;
            sol [i + n] += 2 * i + 1;
        }
        for (int i = 0; i < 2 * n; ++i) {
            std::cout << sol [i] << ' ';
        }
    }

    return 0;
}