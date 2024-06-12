#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(acc);
    int n, k; std::cin >> n >> k;
    int* values = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> values [i];
    long long curtot = values [0];
    long long* options = new long long[n - 1]{};
    for (int i = 0; i < n - 1; ++i) {
        curtot += values [i + 1];
        options [i] = curtot;
    }

    std::sort(options, options + n - 1, std::greater<long long>());
    long long max = 0;
    for (int i = 0; i < k; ++i) {
        if (options [i] > 0) max += options [i];
        else break;
    }

    std::cout << max;

    return 0;
}