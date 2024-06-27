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
        std::sort(a, a + n);
        int cur = 0;
        long long q1 = 0LL;
        long long q2 = 0LL;
        std::vector<long long> num;
        num.push_back(0LL);
        int prev = a [0];
        for (int i = 0; i < n; ++i) {
            if (a [i] == prev) ++num.back();
            else {
                prev = a [i];
                num.push_back(1LL);
            }
            if (a [i] == 1) ++q1;
            if (a [i] == 2) ++q2;
        }
        long long combos = 0;
        for (auto& val : num) {
            combos += (val * (val - 1)) >> 1;
        }
        combos += q1 * q2;
        std::cout << combos << '\n';
    }

    return 0;
}