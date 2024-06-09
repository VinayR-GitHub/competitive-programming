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
    FILE(spies);
    int n; std::cin >> n;
    int* xi = new int[n]{}; int* yi = new int[n]{};
    for (int i = 0; i < n; ++i) std::cin >> xi [i] >> yi [i];
    std::sort(xi, xi + n); std::sort(yi, yi + n);

    std::cout << xi [(n - 1) / 2] << ' ' << yi [(n - 1) / 2];

    return 0;
}