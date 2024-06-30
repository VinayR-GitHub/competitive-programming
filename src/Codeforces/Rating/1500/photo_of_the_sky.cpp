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
    long long* a = new long long[2 * n]{};
    for (int i = 0; i < 2 * n; ++i) {
        std::cin >> a [i];
    }
    std::sort(a, a + 2 * n);
    long long diffx = a [n - 1] - a [0];
    long long diffy = a [2 * n - 1] - a [n];
    long long min =  diffx * diffy;
    diffx = a [2 * n - 1] - a [0];
    for (int i = 1; i < n; ++i) {
        diffy = a [n + i - 1] - a [i];
        min = MIN(min, diffx * diffy);
    }
    std::cout << min;
    return 0;
}