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
        std::string a; std::cin >> a;
        int left = 0;
        int right = 0;
        for (int i = 0; i < n; ++i) {
            right += a [i] == '1';
        }
        std::vector<std::pair<int, int>> options;
        if (right >= (n + 1) / 2) {
            options.push_back(PAIR(0, 0));
        }
        for (int i = 0; i < n; ++i) {
            left += a [i] == '0';
            right -= a [i] == '1';
            if (left > i / 2 && right >= (n - i) / 2) {
                options.push_back(PAIR(i + 1, i + 1));
            }
        }
        for (int i = 0; i < options.size(); ++i) {
            options [i].first = MAG(n - 2 * options [i].first);
        }
        std::sort(options.begin(), options.end());
        std::cout << options [0].second << '\n';
    }

    return 0;
}