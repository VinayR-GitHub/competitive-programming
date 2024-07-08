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
    int n; std::cin >> n;
    std::deque<int>* couples = new std::deque<int>[n]{};
    int ai;
    for (int i = 0; i < 2 * n; ++i) {
        std::cin >> ai;
        couples [ai - 1].push_back(i);
    }
    int num = 0;
    for (int i = 0; i < n; ++i) {
        if (couples [i].back() - couples [i].front() == 2) {
            ++num;
        }
    }
    std::cout << num;
    return 0;
}