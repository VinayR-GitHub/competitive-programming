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
        int* res = new int[n]{};
        std::deque<int> fillers;
        for (int i = 0; i < n; ++i) {
            fillers.push_back(i + 1);
        }
        std::deque<std::pair<bool, int>> order;
        int modulo = 0;
        int cur = 0;
        bool dir = true;
        while (order.size() < n) {
            order.push_back(PAIR(dir, cur * k + modulo));
            ++cur;
            if (cur * k + modulo >= n) {
                ++modulo;
                cur = 0;
                dir = !dir;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (order.front().first) {
                res [order.front().second] = fillers.front();
                fillers.pop_front();
            } else {
                res [order.front().second] = fillers.back();
                fillers.pop_back();
            }
            order.pop_front();
        }
        for (int i = 0; i < n; ++i) {
            std::cout << res [i] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}