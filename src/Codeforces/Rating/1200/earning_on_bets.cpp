#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    ACCEL();
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        int* k = new int[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> k [i];
        }

        std::function<int(int, int)> gcd;
        gcd = [](int a, int b)->int {
            while (b)
                b ^= a ^= b ^= a %= b;
            return a;
        };

        long long lcm = 1;
        for (int i = 0; i < n; ++i) {
            lcm /= gcd(lcm, k [i]);
            lcm *= k [i];
        }

        long long count = 0;
        for (int i = 0; i < n; ++i) {
            count += lcm / k [i];
        }
        
        if (count >= lcm) std::cout << "-1\n";
        else {
            for (int i = 0; i < n; ++i) {
                std::cout << lcm / k [i] << ' ';
            }
            std::cout << '\n';
        }
    }

    return 0;
}