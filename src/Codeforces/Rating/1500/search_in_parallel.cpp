#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int t; std::cin >> t;
    while (t--) {
        int n, s1, s2; std::cin >> n >> s1 >> s2;
        std::pair<int, int>* r = new std::pair<int, int>[n]{};
        int ri;
        for (int i = 0; i < n; ++i) {
            std::cin >> ri;
            r [i] = PAIR(ri, i);
        }
        std::sort(r, r + n, std::greater<std::pair<int, int>>());
        int* timea = new int[n]{};
        int* timeb = new int[n]{};
        for (int i = 0; i < n; ++i) {
            timea [i] = s1 * i + s1;
            timeb [i] = s2 * i + s2;
        }
        int iter1 = 0;
        int iter2 = 0;
        int* order = new int[n]{};
        for (int i = 0; i < n; ++i) {
            if (timea [iter1] <= timeb [iter2]) {
                order [i] = 1;
                ++iter1;
            } else {
                order [i] = 2;
                ++iter2;
            }
        }
        std::deque<int> a;
        std::deque<int> b;
        for (int i = 0; i < n; ++i) {
            if (order [i] == 1) {
                a.push_back(r [i].second + 1);
            } else {
                b.push_back(r [i].second + 1);
            }
        }
        std::cout << a.size() << ' ';
        while (a.size()) {
            std::cout << a.front() << ' ';
            a.pop_front();
        }
        std::cout << '\n';
        std::cout << b.size() << ' ';
        while (b.size()) {
            std::cout << b.front() << ' ';
            b.pop_front();
        }
        std::cout << '\n';
    }
    return 0;
}