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
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
        }
        if (n == 2) {
            std::cout << "0\n";
            continue;
        }
        long long cost = 0LL;
        for (int i = 0; i < n - 1; ++i) {
            cost += MAG(a [i + 1] - a [i]);
        }
        long long* saving = new long long[n]{};
        for (int i = 1; i < n - 1; ++i) {
            long long leftdiff = 0LL;
            long long rghtdiff = 0LL;
            leftdiff = MAG(a [i] - a [i - 1]);
            rghtdiff = MAG(a [i + 1] - a [i]);
            long long prmediff = 0LL;
            saving [i] = leftdiff + rghtdiff - MAG(a [i + 1] - a [i - 1]);
        }
        saving [0] = MAG(a [1] - a [0]);
        saving [n - 1] = MAG(a [n - 1] - a [n - 2]);
        std::sort(saving, saving + n, std::greater<long long>());
        cost -= saving [0];
        std::cout << cost << '\n';
    }
    return 0;
}