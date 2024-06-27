#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int n, m; std::cin >> n >> m;
    int* c = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> c [i];
    }
    std::vector<int>* adj = new std::vector<int>[n]{};
    int xi, yi;
    for (int i = 0; i < m; ++i) {
        std::cin >> xi >> yi;
        adj [xi - 1].push_back(yi);
        adj [yi - 1].push_back(xi);
    }
    int* visited = new int[n]{};
    std::deque<int> bfs;
    for (int i = 0; i < n; ++i) {
        if (visited [i]) continue;
        bfs.push_back(i + 1);
        while (bfs.size()) {
            int node = bfs.front();
            bfs.pop_front();
            if (visited [node - 1]) continue;
            visited [node - 1] = i + 1;
            for (auto& vertex : adj [node - 1]) {
                bfs.push_back(vertex);
            }
        }
    }
    long long* mincosts = new long long[n]{};
    for (int i = 0; i < n; ++i) {
        mincosts [i] = LLONG_MAX;
    }
    for (int i = 0; i < n; ++i) {
        mincosts [visited [i] - 1] = MIN(mincosts [visited [i] - 1], static_cast<long long>(c [i]));
    }
    long long cost = 0;
    for (int i = 0; i < n; ++i) {
        if (mincosts [i] != LLONG_MAX) {
            cost += mincosts [i];
        }
    }
    std::cout << cost;
    return 0;
}