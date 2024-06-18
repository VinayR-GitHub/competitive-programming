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
        for (int i = 0; i < n; ++i) std::cin >> a [i];
        std::pair<int, std::pair<int, int>>* mod = new std::pair<int, std::pair<int, int>>[n]{};
        std::pair<int, int>* num = new std::pair<int, int>[n]{};
        for (int i = 0; i < n; ++i) {
            mod [i] = PAIR(a [i] / 4, PAIR(a [i], i));
            num [i] = PAIR(mod [i].first, i);
        }
        std::sort(mod, mod + n);
        std::sort(num, num + n);
        int* res = new int[n]{};
        for (int i = 0; i < n; ++i) {
            res [num [i].second] = mod [i].second.first;
        }
        for (int i = 0; i < n; ++i) std::cout << res [i] << ' ';
        std::cout << '\n';
    }

    return 0;
}