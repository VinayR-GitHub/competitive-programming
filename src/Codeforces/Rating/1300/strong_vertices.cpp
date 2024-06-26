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
        long long* a = new long long[n]{};
        long long* b = new long long[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b [i];
        }
        std::pair<long long, int>* d = new std::pair<long long, int>[n]{};
        for (int i = 0; i < n; ++i) {
            d [i] = PAIR(a [i] - b [i], i + 1);
        }
        std::sort(d, d + n, std::greater<std::pair<long long, int>>());

        long long max = d [0].first;
        int count = 0;
        std::vector<int> vals;
        for (int i = 0; i < n; ++i) {
            if (d [i].first == max) {
                ++count;
                vals.push_back(d [i].second);
            }
            else break;
        }

        std::sort(vals.begin(), vals.end());

        std::cout << count << '\n';
        for (auto& val : vals) {
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}