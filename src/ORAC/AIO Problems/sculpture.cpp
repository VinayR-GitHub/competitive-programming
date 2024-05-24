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
    FILE(sculp);
    int n; std::cin >> n; int ai, xi, bi, yi;
    std::pair<int, int>* adj_to_root = new std::pair<int, int>[n]{}; // PAIR(root, len)
    for (int i = 0; i < n; ++i) {
        std::cin >> ai >> xi >> bi >> yi;
        if (ai) {
            adj_to_root [ai - 1] = PAIR(i + 1, xi);
            adj_to_root [bi - 1] = PAIR(i + 1, yi);
        }
    }
    
    int changes = 0;

    while (n != 1) {
        changes += std::abs(adj_to_root [n - 2].second - adj_to_root [n - 1].second);
        adj_to_root [adj_to_root [n - 1].first - 1].second += MAX(adj_to_root [n - 2].second, adj_to_root [n - 1].second);
        n -= 2;
    }

    std::cout << changes;

    return 0;
}