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
        long long x, y, z, k; std::cin >> x >> y >> z >> k;
        long long max = 0;
        std::vector<long long> bigfacts;
        long long a = MAX(x, MAX(y, z));
        long long c = MIN(x, MIN(y, z));
        long long b = x + y + z - a - c;
        for (int i = 1; i < a + 1; ++i) {
            if (k % i == 0) {
                bigfacts.push_back(i);
            }
        }
        
        for (auto& fact : bigfacts) {
            std::vector<long long> midfacts;
            long long k2 = k / fact;
            for (int i = 1; i < b + 1; ++i) {
                if (k2 % i == 0) {
                    midfacts.push_back(i);
                }
            }

            for (auto& mini : midfacts) {
                long long k3 = k2 / mini;
                if (k3 < c + 1) {
                    max = MAX(max, (a - fact + 1) * (b - mini + 1) * (c - k3 + 1));
                }
            }
        }

        std::cout << max << '\n';
    }

    return 0;
}