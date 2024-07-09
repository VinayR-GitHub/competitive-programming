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
        std::map<int, int> primecounts;
        int* a = new int[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
            int k = a [i];
            for (int j = 2; j <= std::sqrt(k) + 0.0001; ++j) {
                while (k % j == 0) {
                    k /= j;
                    ++primecounts [j];
                }
            }
            if (k != 1) {
                ++primecounts [k];
            }
        }
        bool can = true;
        for (auto& obj : primecounts) {
            if (obj.second % n && obj.first != 1) {
                can = false;
                break;
            }
        }
        if (can) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    return 0;
}