#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        int li, ri;
        std::pair<long long, long long>* lri = new std::pair<long long, long long>[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> li >> ri;
            lri [i] = PAIR(li, ri);
        }

        std::function<int(long long)> solve;
        solve = [&](long long k)->int {
            long long mincoord = 0LL;
            long long maxcoord = 0LL;
            for (int i = 0; i < n; ++i) {
                mincoord = MAX(mincoord - k, lri [i].first);
                maxcoord = MIN(maxcoord + k, lri [i].second);
                if (mincoord > maxcoord) {
                    return 0;
                }
            }
            return 1;
        };
    
        long long low = -1LL;
        long long high = 1000000000LL;
        while (low + 1 < high) {
            long long med = (low + high) >> 1;
            if (solve(med)) {
                high = med;
            } else {
                low = med;
            }
        }
        std::cout << high << '\n';
    }
    return 0;
}