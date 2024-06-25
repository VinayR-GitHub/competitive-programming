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
        int* a = new int[n]{};
        for (int i = 0; i < n; ++i) std::cin >> a [i];
        std::vector<int> factors;
        for (int i = 0; i < n; ++i) {
            if (n % (i + 1) == 0) {
                factors.push_back(i + 1);
            }
        }
        long long maxdiff = 0;
        for (auto& factor : factors) {
            long long mintruck = LLONG_MAX;
            long long maxtruck = LLONG_MIN;
            int opp = n / factor;
            for (int i = 0; i < opp; ++i) {
                long long truck = 0;
                for (int j = 0; j < factor; ++j) {
                    truck += a [i * factor + j];
                }
                mintruck = MIN(mintruck, truck);
                maxtruck = MAX(maxtruck, truck);
            }
            maxdiff = MAX(maxdiff, maxtruck - mintruck);
        }

        std::cout << maxdiff << '\n';
    }

    return 0;
}