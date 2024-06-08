#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL); \
    freopen(#id ".in", "r", stdin); \
    freopen(#id ".out", "w", stdout)

int main() {
    FILE(snurgle);
    int n; std::cin >> n; int next;
    std::vector<int>* adj = new std::vector<int>[n]{};
    for (int i = 1; i < n; ++i) std::cin >> next, adj [next - 1].push_back(i);

    std::function<std::pair<int, int>(int)> recursor;
    recursor = [&](int node)->std::pair<int, int> {
        if (adj [node - 1].empty()) return PAIR(0, 1);
        int odd = 0, even = 1;
        for (auto& vertex : adj [node - 1]) {
            std::pair<int, int> next = recursor(vertex);
            even += next.first;
            odd += MAX(next.first, next.second);
        }
        return PAIR(odd, even);
    };

    std::pair<int, int> eo = recursor(n);

    std::cout << MAX(eo.first, eo.second);

    return 0;
}