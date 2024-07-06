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
    FILE(drive);
    int s; std::cin >> s;
    int* styles = new int[s]{};
    for (int i = 0; i < s; ++i) {
        std::cin >> styles [i];
    }
    int n, h; std::cin >> n >> h;
    std::vector<std::pair<int, int>>* adj = new std::vector<std::pair<int, int>>[n]{};
    int t; std::cin >> t;
    int xi, yi, mi;
    while (t--) {
        std::cin >> xi >> yi >> mi;
        adj [xi - 1].push_back(PAIR(yi, mi));
        adj [yi - 1].push_back(PAIR(xi, mi));
    }
    int* bestchoice = new int[(s + 1) * n]{};
    for (int i = 0; i < (s + 1) * n; ++i) {
        bestchoice [i] = INT_MAX;
    }
    bestchoice [h - 1] = 0;
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < n; ++j) {
            if (bestchoice [i * n + j] == INT_MAX) continue;
            for (auto& vertex : adj [j]) {
                if (styles [i] == vertex.second) {
                    bestchoice [(i + 1) * n + vertex.first - 1] = MIN(bestchoice [(i + 1) * n + vertex.first - 1], bestchoice [i * n + j]);
                } else {
                    bestchoice [(i + 1) * n + vertex.first - 1] = MIN(bestchoice [(i + 1) * n + vertex.first - 1], 1 + bestchoice [i * n + j]);
                }
            }
        }
    }
    std::cout << bestchoice [s * n + h - 1];
    return 0;
}