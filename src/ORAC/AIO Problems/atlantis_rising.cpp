#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(atlan);
    int n; std::cin >> n;
    int* heights = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> heights [i];
    int curmax = INT_MIN; int* possible = new int[n]{};
    for (int i = 0; i < n; ++i) {
        if (heights [i] >= curmax) curmax = heights [i];
        else possible [i] = 1;
    }
    curmax = INT_MIN;
    int count = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (heights [i] >= curmax) curmax = heights [i];
        else if (possible [i]) ++count;
    }

    std::cout << count;

    return 0;
}