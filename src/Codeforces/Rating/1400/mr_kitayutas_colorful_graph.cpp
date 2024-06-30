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
    int n, m; std::cin >> n >> m;
    std::vector<std::pair<int, int>>* adj = new std::vector<std::pair<int, int>>[n]{};
    int ai, bi, ci;
    for (int i = 0; i < m; ++i) {
        std::cin >> ai >> bi >> ci;
        adj [ai - 1].push_back(PAIR(bi, ci));
        adj [bi - 1].push_back(PAIR(ai, ci));
    }
    int* colouring = new int[m * n]{};
    int* visited = new int[m * n]{};
    std::deque<int> bfs;
    for (int col = 0; col < m; ++col) {
        for (int i = 0; i < n; ++i) {
            if (visited [col * n + i]) continue;
            bfs.push_back(i + 1);
            while (bfs.size()) {
                int node = bfs.front();
                bfs.pop_front();
                if (visited [col * n + node - 1]) continue;
                visited [col * n + node - 1] = 1;
                colouring [col * n + node - 1] = i;
                for (auto& vertex : adj [node - 1]) {
                    if (vertex.second == col + 1) {
                        bfs.push_back(vertex.first);
                    }
                }
            }
        }
    }
    int q; std::cin >> q;
    int ui, vi;
    while (q--) {
        std::cin >> ui >> vi;
        int count = 0;
        for (int col = 0; col < m; ++col) {
            if (colouring [col * n + ui - 1] == colouring [col * n + vi - 1]) {
                ++count;
            }
        }
        std::cout << count << '\n';
    }
    return 0;
}