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
        int n, x; std::cin >> n >> x;
        int* a = new int[n]{};
        int tot = 0;
        int min = INT_MAX;
        int max = INT_MIN;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
            tot += a [i];
            max = MAX(max, a [i]);
            min = MIN(min, a [i]);
            if (a [i] == x) {
                ++count;
            }
        }
        if (min == x && max == x) {
            std::cout << "0\n";
        } else if (tot == n * x || count) {
            std::cout << "1\n";
        } else {
            std::cout << "2\n";
        }
    }
    return 0;
}