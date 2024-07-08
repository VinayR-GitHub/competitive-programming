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
    int n; std::cin >> n;
    std::vector<std::pair<int, long long>>* adj = new std::vector<std::pair<int, long long>>[n]{};
    int ai, bi;
    long long ci;
    long long bestdist = 0LL;
    for (int i = 1; i < n; ++i) {
        std::cin >> ai >> bi >> ci;
        adj [ai - 1].push_back(PAIR(bi, ci));
        adj [bi - 1].push_back(PAIR(ai, ci));
        bestdist += ci;
        bestdist += ci;
    }
    short* visited = new short[n]{};
    long long* dist = new long long[n]{};
    for (int i = 1; i < n; ++i) {
        dist [i] = LLONG_MAX >> 2;
    }
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> dijkstra;
    dijkstra.push(PAIR(0LL, 1));
    while (dijkstra.size()) {
        int node = dijkstra.top().second;
        dijkstra.pop();
        if (visited [node - 1]) continue;
        visited [node - 1] = 1;
        for (auto& vertex : adj [node - 1]) {
            dist [vertex.first - 1] = MIN(dist [vertex.first - 1], dist [node - 1] + vertex.second);
            dijkstra.push(PAIR(dist [vertex.first - 1], vertex.first));
        }
    }
    long long maxdist = 0LL;
    int maxnode = 1;
    for (int i = 0; i < n; ++i) {
        visited [i] = 0;
        if (dist [i] > maxdist) {
            maxdist = dist [i];
            maxnode = i + 1;
        }
        dist [i] = LLONG_MAX >> 2;
    }
    dist [maxnode - 1] = 0LL;
    dijkstra.push(PAIR(0LL, maxnode));
    while (dijkstra.size()) {
        int node = dijkstra.top().second;
        dijkstra.pop();
        if (visited [node - 1]) continue;
        visited [node - 1] = 1;
        for (auto& vertex : adj [node - 1]) {
            dist [vertex.first - 1] = MIN(dist [vertex.first - 1], dist [node - 1] + vertex.second);
            dijkstra.push(PAIR(dist [vertex.first - 1], vertex.first));
        }
    }
    long long diameter = 0LL;
    for (int i = 0; i < n; ++i) {
        diameter = MAX(diameter, dist [i]);
    }
    bestdist -= diameter;
    std::cout << bestdist;
    return 0;
}