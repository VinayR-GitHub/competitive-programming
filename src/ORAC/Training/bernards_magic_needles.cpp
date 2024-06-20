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
    FILE(bernard);
    int n; std::cin >> n;
    int* haystack = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> haystack [i];
    }

    int q;
    while (true) {
        std::cin >> q;
        if (q == -1) break;
        int iter = std::lower_bound(haystack, haystack + n, q) - haystack;
        if (haystack [iter] == q) {
            std::cout << iter + 1 << '\n';
        } else {
            std::cout << "needle is gone forever\n";
        }
    }

    return 0;
}