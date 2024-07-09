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
        int count = 0;
        int best = 0;
        long long tot = 0LL;
        int ai;
        while (n--) {
            std::cin >> ai;
            best = MAX(best, ai);
            tot += ai;
            if (tot == best * 2) {
                ++count;
            }
        }
        std::cout << count << '\n';
    }
    return 0;
}