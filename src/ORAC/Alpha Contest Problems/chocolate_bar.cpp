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
    int* tastes = new int[n]{};
    int lsum = 0, rsum = 0;
    for (int i = 0; i < n; ++i) std::cin >> tastes [i], rsum += tastes [i];

    int mad = INT_MAX;
    for (int i = 0; i < n - 1; ++i) {
        lsum += tastes [i];
        rsum -= tastes [i];
        mad = MIN(mad, MAG(lsum - rsum));
    }

    std::cout << mad;

    return 0;
}