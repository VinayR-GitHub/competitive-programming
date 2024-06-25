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
    int n, k; std::cin >> n >> k;
    int* a = new int[n]{};
    int* b = new int[n]{};
    
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b [i];
    }

    long long cost = 0;
    int* d = new int[n]{};
    for (int i = 0; i < n; ++i) {
        d [i] = b [i] - a [i];
        cost += a [i];
    }
    std::sort(d, d + n);
    
    int iter = std::upper_bound(d, d + n, 0) - d;
    iter = MIN(iter, n - k);

    for (int i = 0; i < iter; ++i) {
        cost += d [i];
    }

    std::cout << cost;
    return 0;
}