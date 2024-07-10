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
        long long sum = 0LL;
        int ai;
        for (int i = 0; i < n - 1; ++i) {
            std::cin >> ai;
            sum += ai;
        }
        sum *= -1;
        std::cout << sum << '\n';
    }
    return 0;
}