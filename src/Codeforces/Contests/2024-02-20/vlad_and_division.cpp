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
        std::deque<int> left;
        std::deque<int> right;
        int temp;
        for (int i = 0; i < n; ++i) {
            std::cin >> temp;
            left.push_back(temp);
            right.push_back(temp);
        }
        std::sort(left.begin(), left.end());
        std::sort(right.begin(), right.end(), std::greater<int>());
        int num = 2 * n;
        while (left.size() && right.size()) {
            if (left.front() + right.front() == INT_MAX) {
                --num;
                left.pop_front();
                right.pop_front();
            } else if (left.front() + right.front() < 0) {
                right.pop_front();
            } else {
                left.pop_front();
            }
        }
        std::cout << num / 2 << '\n';
    }
    return 0;
}