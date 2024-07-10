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
        int n, c, d;
        std::cin >> n >> c >> d;
        int* a = new int[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
        }
        std::sort(a, a + n);
        long long basecost = 0LL;
        std::vector<int> relevants;
        relevants.push_back(0);
        relevants.push_back(a [0]);
        for (int i = 1; i < n; ++i) {
            if (a [i] != a [i - 1]) {
                relevants.push_back(a [i]);
            } else {
                basecost += c;
            }
        }
        long long mincost = static_cast<long long>(n) * static_cast<long long>(c) + static_cast<long long>(d);
        if (a [0] == 1) {
            mincost -= c;
        }
        int k = relevants.size() - 1;
        long long curcost = 1LL * static_cast<long long>(k) * static_cast<long long>(c);
        for (int i = 1; i < k + 1; ++i) {
            curcost -= c;
            curcost += 1LL * static_cast<long long>(d) * static_cast<long long>(relevants [i] - relevants [i - 1] - 1);
            mincost = MIN(mincost, curcost + basecost);
        }
        std::cout << mincost << '\n';
    }
    return 0;
}