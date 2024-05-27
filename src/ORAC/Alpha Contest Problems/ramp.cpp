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
    int cur; std::cin >> cur; int temp;
    int max = 1; int curmax = 1;
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> temp;
        if (temp == cur + 1) ++curmax, max = MAX(max, curmax);
        else curmax = 1;
        cur = temp;
    }

    std::cout << max;

    return 0;
}