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
        int a;
        long long tot = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a;
            tot += a;
        }
        if (tot % n == 0) std::cout << "0\n";
        else std::cout << "1\n";
    }

    return 0;
}