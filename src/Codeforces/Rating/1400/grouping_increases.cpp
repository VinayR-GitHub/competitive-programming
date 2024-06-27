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
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
        }
        std::deque<int> x;
        x.push_front(INT_MAX);
        std::deque<int> y;
        y.push_front(INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (a [i] <= MIN(x.back(), y.back())) {
                if (x.back() < y.back()) {
                    x.push_back(a [i]);
                } else {
                    y.push_back(a [i]);
                }
            } else if (a [i] > MAX(x.back(), y.back())) {
                if (x.back() < y.back()) {
                    x.push_back(a [i]);
                } else {
                    y.push_back(a [i]);
                }
            } else {
                if (x.back() < y.back()) {
                    y.push_back(a [i]);
                } else {
                    x.push_back(a [i]);
                }
            }
        }
        x.pop_front();
        y.pop_front();
        int penalty = 0;
        int X = x.size();
        int Y = y.size();
        for (int i = 0; i < X - 1; ++i) {
            int stor = x.front();
            x.pop_front();
            if (stor < x.front()) ++penalty;
        }
        for (int i = 0; i < Y - 1; ++i) {
            int stor = y.front();
            y.pop_front();
            if (stor < y.front()) ++penalty;
        }
        std::cout << penalty << '\n';
    }
    return 0;
}