#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int* cache = new int[10]{};
    for (int d = 0; d < 10; ++d) {
        std::vector<std::pair<int, std::pair<int, int>>> choices;
        for (int i = 0; i <= d; ++i) {
            for (int j = 0; j <= d - i; ++j) {
                choices.push_back(PAIR(MIN(MIN(i, j), d - i - j), PAIR(d - MIN(MIN(i, j), d - i - j) - MAX(MAX(i, j), d - i - j), MAX(MAX(i, j), d - i - j))));
            }
        }
        cache [d] = choices.size();
    }
    int t; std::cin >> t;
    while (t--) {
        std::string n;
        std::cin >> n;
        long long tot = 1LL;
        for (int i = 0; i < n.length(); ++i) {
            int dig = n [i] - 48;
            tot *= 1LL * cache [dig];
        }
        std::cout << tot << '\n';
    }
    return 0;
}