#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        if (n == 1) std::cout << "FastestFinger\n";
        else if (n == 2) std::cout << "Ashishgup\n";
        else {
            int num = 0;
            while (n % 2 == 0) {
                n >>= 1;
                ++num;
            }

            if (n == 1 && num != 1) {
                std::cout << "FastestFinger\n";
            } else if (num == 1) {
                bool is_prime = true;
                for (int i = 2; i < sqrt(n) + 1; ++i) {
                    if (n % i == 0) {
                        is_prime = false;
                        break;
                    }
                }

                if (is_prime) std::cout << "FastestFinger\n";
                else std::cout << "Ashishgup\n";
            } else {
                std::cout << "Ashishgup\n";
            }
        }
    }

    return 0;
}