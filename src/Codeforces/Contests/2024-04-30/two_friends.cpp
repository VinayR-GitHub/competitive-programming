#include <iostream>
#include <array>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        int* p_ = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> p_ [i];
        bool can = false;
        for (int i = 0; i < n; ++i) {
            if (p_ [p_ [i] - 1] == (i + 1)) {
                can = true;
                break;
            }
        }

        std::cout << ((can) ? "2\n" : "3\n");
    }

    return 0;
}