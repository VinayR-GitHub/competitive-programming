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
        int n, k; std::cin >> n >> k;
        std::function<int(int, int, int)> recursor;
        recursor = [&](int n, int k, int multip)->int {
            int oddnum = n / 2;
            if (n & 1) ++oddnum;
            if (k <= oddnum) {
                return multip * (2 * k - 1);
            } else {
                return recursor(n - oddnum, k - oddnum, multip * 2);
            }
        };
        std::cout << recursor(n, k, 1) << '\n';
    }
    return 0;
}