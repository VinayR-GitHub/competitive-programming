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
    FILE(where);
    int n, m, k; std::cin >> n >> m; int ai, bi, ci;
    std::vector<std::pair<int, int>>* adj = new std::vector<std::pair<int, int>>[n]{}; // PAIR(CITY, TRANSPORT)
    for (int i = 0; i < m; ++i) std::cin >> ai >> bi >> ci, adj [ai - 1].emplace_back(PAIR(bi, ci)), adj [bi - 1].emplace_back(PAIR(ai, ci));
    std::cin >> k; int* transport = new int[k]{}; for (int i = 0; i < k; ++i) std::cin >> transport [i];
    
    int* pe = new int[n]{}; int* po = new int[n]{};

    for (int i = 0; i < n; ++i) {
        for (auto& cit : adj [i]) {
            if (cit.second == transport [0]) po [cit.first - 1] = 1;
        }
    }

    for (int i = 1; i < k; ++i) {
        if (i & 1) {
            for (int j = 0; j < n; ++j) {
                if (po [j]) {
                    for (auto& next : adj [j]) {
                        if (next.second == transport [i]) pe [next.first - 1] = 1;
                    }
                }
            }
            for (int it = 0; it < n; ++it) po [it] = 0;
        } else {
            for (int j = 0; j < n; ++j) {
                if (pe [j]) {
                    for (auto& next : adj [j]) {
                        if (next.second == transport [i]) po [next.first - 1] = 1;
                    }
                }
            }
            for (int it = 0; it < n; ++it) pe [it] = 0;
        }
    }

    int cnt = 0;
    if (k & 1) {
        for (int i = 0; i < n; ++i) if (po [i]) ++cnt;
        if (!cnt) std::cout << "Impossible";
        else for (int i = 0; i < n; ++i) if (po [i]) std::cout << (i + 1) << '\n';
    } else {
        for (int i = 0; i < n; ++i) if (pe [i]) ++cnt;
        if (!cnt) std::cout << "Impossible";
        else for (int i = 0; i < n; ++i) if (pe [i]) std::cout << (i + 1) << '\n';
    }

    return 0;
}