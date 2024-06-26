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
        int n, ai; std::cin >> n;

        std::deque<int> evens;
        std::deque<int> odds;
        for (int i = 0; i < 2 * n; ++i) {
            std::cin >> ai;
            if (ai & 1) odds.push_back(i + 1);
            else evens.push_back(i + 1);
        }

        if (evens.size() & 1) {
            evens.pop_back();
            odds.pop_back();
        } else {
            if (evens.size()) {
                evens.pop_back();
                evens.pop_back();
            } else {
                odds.pop_back();
                odds.pop_back();
            }
        }

        int me = evens.size() >> 1;
        int mo = odds.size() >> 1;

        for (int i = 0; i < me; ++i) {
            std::cout << evens.front() << ' ';
            evens.pop_front();
            std::cout << evens.front() << '\n';
            evens.pop_front();
        }
        for (int i = 0; i < mo; ++i) {
            std::cout << odds.front() << ' ';
            odds.pop_front();
            std::cout << odds.front() << '\n';
            odds.pop_front();
        }
    }

    return 0;
}