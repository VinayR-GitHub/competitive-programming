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
        int n; std::cin >> n; int temp;
        std::pair<int, int>* a = new std::pair<int, int>[n]{};
        for (int i = 0; i < n; ++i) std::cin >> temp, a [i] = PAIR(temp, i);
        int res = a [n - 1].first;
        std::sort(a, a + n, std::greater<std::pair<int, int>>());
        if (a [0].second != n - 1) res += a [0].first;
        else res += a [1].first;
        std::cout << res << '\n';
    }

    return 0;
}