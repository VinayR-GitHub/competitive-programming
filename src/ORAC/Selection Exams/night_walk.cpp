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
    FILE(night);
    double cx, cy; std::cin >> cx >> cy;
    double bx, by; std::cin >> bx >> by;
    int n; std::cin >> n;
    std::pair<double, double>* points = new std::pair<double, double>[n + 2]{};
    double xi, yi;
    for (int i = 0; i < n; ++i) {
        std::cin >> xi >> yi;
        points [i] = PAIR(xi, yi);
    }
    points [n] = PAIR(cx, cy);
    points [n + 1] = PAIR(bx, by);
    std::vector<std::pair<int, int>>* adj = new std::vector<std::pair<int, int>>[n + 2]{};
    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < i; ++j) {
            double dist = (points [i].first - points [j].first) * (points [i].first - points [j].first) + (points [i].second - points [j].second) * (points [i].second - points [j].second);
            if (dist <= 2500.0) {
                dist = std::sqrt(dist);
                adj [i].push_back(PAIR(j, 100000 * dist));
                adj [j].push_back(PAIR(i, 100000 * dist));
            }
        }
    }
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> dijkstra;
    dijkstra.push(PAIR(0, n));
    int* visited = new int[n + 2]{};
    int* distances = new int[n + 2]{};
    for (int i = 0; i < n; ++i) {
        distances [i] = INT_MAX;
    }
    distances [n + 1] = INT_MAX;
    while (dijkstra.size()) {
        int node = dijkstra.top().second;
        dijkstra.pop();
        if (visited [node]) continue;
        visited [node] = 1;
        for (auto& vertex : adj [node]) {
            distances [vertex.first] = MIN(distances [vertex.first], distances [node] + vertex.second);
            dijkstra.push(PAIR(distances [vertex.first], vertex.first));
        }
    }
    double res = distances [n + 1];
    res /= 100000.0;
    std::cout << res;
    return 0;
}