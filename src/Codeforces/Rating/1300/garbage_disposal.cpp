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

    long long bags = 0;
    long long cur = 0;
    long long prev = 0;
    for (int i = 0; i < n; ++i) {
        cur += a [i];
        long long change = cur / k;
        bags += change;
        change *= k;
        cur %= k;
        
        if (change < prev && cur) {
            cur = 0;
            ++bags;
        }
        prev = cur;
    }

    if (cur) ++bags;
    std::cout << bags;
    return 0;
}