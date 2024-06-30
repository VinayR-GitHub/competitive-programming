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
        int n, k; std::cin >> n >> k;
        int ai;
        std::set<int> a;
        for (int i = 0; i < n; ++i) {
            std::cin >> ai;
            a.insert(ai);
        }
        if (a.size() == 1) {
            std::cout << "1\n";
        } else if (k == 1) {
            std::cout << "-1\n";
        } else {
            int res = (a.size() - 1) / (k - 1);
            if ((a.size() - 1) % (k - 1) != 0) ++res;
            std::cout << res << '\n';
        }
    }
    return 0;
}