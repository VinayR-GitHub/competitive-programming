#include <iostream>
#include <array>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;
    while (t--) {
        int n, k; std::cin >> n >> k;
        int* cardnums = new int[101]{}; int temp;
        for (int i = 0; i < n; ++i) std::cin >> temp, ++cardnums [temp];
        if (n < k) {
            std::cout << n << '\n';
            continue;
        }
        int max = 0; for (int i = 0; i < 101; ++i) max = MAX(max, cardnums [i]);
        if (max >= k) {
            std::cout << (k - 1) << '\n';
        } else {
            std::cout << n << '\n';
        }
    }

    return 0;
}