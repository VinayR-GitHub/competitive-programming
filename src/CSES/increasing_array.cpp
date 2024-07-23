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
    int* a = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
    }
    long long pluses = 0LL;
    for (int i = 1; i < n; ++i) {
        pluses += MAX(0, a [i - 1] - a [i]);
        a [i] = MAX(a [i], a [i - 1]);
    }
    std::cout << pluses;
    return 0;
}