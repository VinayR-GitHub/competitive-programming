#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int n; std::cin >> n;
    int* p = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> p [i];
    }
    int* num = new int[n * n]{};
    for (int i = 0; i < n; ++i) {
        std::pair<int, int> iter = PAIR(i, i);
        num [i * n + i] = p [i];
        for (int j = 1; j < p [i]; ++j) {
            if (iter.second) {
                if (!num [iter.first * n + iter.second - 1]) {
                    --iter.second;
                } else {
                    ++iter.first;
                }
            } else {
                ++iter.first;
            }
            num [iter.first * n + iter.second] = p [i];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            std::cout << num [i * n + j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}