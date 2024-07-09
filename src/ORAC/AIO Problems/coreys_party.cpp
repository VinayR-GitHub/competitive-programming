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
    FILE(party);
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    std::set<int>* adj = new std::set<int>[n]{};
    int xi, yi;
    while (m--) {
        std::cin >> xi >> yi;
        adj [xi - 1].insert(yi);
        adj [yi - 1].insert(xi);
    }
    short* excluded = new short[n]{};
    int k = n;
    REPEAT:
        for (int i = 0; i < n; ++i) {
            if (excluded [i]) continue;
            if (adj [i].size() < a || k - adj [i].size() <= b) {
                for (auto& node : adj [i]) {
                    auto iter = adj [node - 1].find(i + 1);
                    adj [node - 1].erase(iter);
                }
                adj [i].clear();
                excluded [i] = 1;
                --k;
                goto REPEAT;
            }
        }
    std::cout << k;
    return 0;
}