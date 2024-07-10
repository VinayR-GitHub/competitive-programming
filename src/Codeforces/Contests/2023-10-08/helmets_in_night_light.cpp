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
        int n, p; std::cin >> n >> p;
        int* a = new int[n]{};
        int* b = new int[n]{};
        std::deque<std::pair<int, std::pair<int, int>>> c;
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b [i];
            c.push_back(PAIR(b [i], PAIR(a [i], i)));
        }
        std::sort(c.begin(), c.end());
        long long totcost = p;
        int num = 1;
        if (n == 1) {
            std::cout << totcost << '\n';
            continue;
        }
        if (p <= c.front().first) {
            totcost = 1LL * static_cast<long long>(p) * static_cast<long long>(n);
            std::cout << totcost << '\n';
            continue;
        }
        while (num < n) {
            if (!c.front().second.first) {
                c.pop_front();
            } else if (c.front().first > 0) {
                if (c.front().first >= p) {
                    break;
                }
                c.front().first *= -1;
            } else {
                totcost -= c.front().first;
                ++num;
                --c.front().second.first;
            }
        }
        if (num < n) {
            totcost += 1LL * static_cast<long long>(p) * static_cast<long long>(n - num);
        }
        std::cout << totcost << '\n';
    }
    return 0;
}