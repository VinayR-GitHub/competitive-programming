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
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
    }
    std::sort(a, a + n);
    int mindiff = INT_MAX;
    for (int i = 0; i <= k; ++i) {
        mindiff = MIN(mindiff, a [n - k - 1 + i] - a [i]);
    }
    std::cout << mindiff;
    return 0;
}