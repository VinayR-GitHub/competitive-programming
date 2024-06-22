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
        int n, k, q; std::cin >> n >> k >> q;
        long long* a = new long long[k + 1]{};
        for (int i = 1; i < k + 1; ++i) std::cin >> a [i];
        a [0] = 0;
        long long* b = new long long[k + 1]{};
        for (int i = 1; i < k + 1; ++i) std::cin >> b [i];
        b [0] = 0;
        long long d;
        for (int i = 0; i < q; ++i) {
            std::cin >> d;
            long long time = 0;
            int iter = std::upper_bound(a, a + k + 1, d) - a - 1;
            time = b [iter];
            time += ((b [iter + 1] - b [iter]) * (d - a [iter])) / (a [iter + 1] - a [iter]);
            std::cout << time << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}