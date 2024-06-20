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
    FILE(left);
    int t; std::cin >> t;
    std::vector<int>* trolleys = new std::vector<int>[10001]{};
    int* is_it = new int[10001]{};
    int xi, yi; int minx = INT_MAX, maxx = INT_MIN;
    for (int i = 0; i < t; ++i) {
        std::cin >> xi >> yi;
        trolleys [xi].push_back(yi);
        is_it [xi] = 1;
        minx = MIN(minx, xi);
        maxx = MAX(maxx, xi);
    }
    for (int i = 0; i < 10001; ++i) {
        std::sort(trolleys [i].begin(), trolleys [i].end());
    }
    std::vector<std::pair<int, int>> mm;

    long long cost = maxx - minx;
    for (int i = 0; i < 10001; ++i) {
        if (is_it [i]) {
            mm.push_back(PAIR(trolleys [i].front(), trolleys [i].back()));
            cost += mm.back().second;
            cost -= mm.back().first;
        }
    }

    std::vector<std::pair<int, int>>* adj = new std::vector<std::pair<int, int>>[2 * mm.size()]{};
    for (int i = 0; i < mm.size() - 1; ++i) {
        adj [2 * i].push_back(PAIR(2 * i + 2, MAG(mm [i].second - mm [i + 1].first)));
        adj [2 * i].push_back(PAIR(2 * i + 3, MAG(mm [i].second - mm [i + 1].second)));
        adj [2 * i + 1].push_back(PAIR(2 * i + 2, MAG(mm [i].first - mm [i + 1].first)));
        adj [2 * i + 1].push_back(PAIR(2 * i + 3, MAG(mm [i].first - mm [i + 1].second)));
    }

    int* visa = new int[2 * mm.size()]{};
    int* visb = new int[2 * mm.size()]{};
    long long* disa = new long long[2 * mm.size()]{};
    long long* disb = new long long[2 * mm.size()]{};
    for (int i = 0; i < 2 * mm.size(); ++i) {
        disa [i] = 1000000000LL;
        disb [i] = 1000000000LL;
    }
    disa [0] = 0LL;
    disb [1] = 0LL;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> dijkstra;

    dijkstra.push(PAIR(0, 0));
    while (dijkstra.size()) {
        int node = dijkstra.top().second;
        dijkstra.pop();
        if (visa [node]) continue;
        visa [node] = 1;
        for (auto& vertex : adj [node]) {
            disa [vertex.first] = MIN(disa [vertex.first], disa [node] + vertex.second);
            dijkstra.push(PAIR(disa [vertex.first], vertex.first));
        }
    }

    dijkstra.push(PAIR(0, 1));
    while (dijkstra.size()) {
        int node = dijkstra.top().second;
        dijkstra.pop();
        if (visb [node]) continue;
        visb [node] = 1;
        for (auto& vertex : adj [node]) {
            disb [vertex.first] = MIN(disb [vertex.first], disb [node] + vertex.second);
            dijkstra.push(PAIR(disb [vertex.first], vertex.first));
        }
    }

    cost += MIN(MIN(disa [2 * mm.size() - 2], disa [2 * mm.size() - 1]), MIN(disb [2 * mm.size() - 2], disb [2 * mm.size() - 1]));

    std::cout << cost;
    return 0;
}