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
    int n, m; long long a, b; std::cin >> n >> a >> b;
    int* heights = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> heights [i];
    std::vector<int>* adj = new std::vector<int>[n]{};
    std::cin >> m; int ui, vi;
    for (int i = 0; i < m; ++i) std::cin >> ui >> vi, adj [ui - 1].push_back(vi), adj [vi - 1].push_back(ui);
    int* visiteda = new int[n]{}; int* visitedb = new int[n]{};
    long long* dista = new long long[n]{}; long long* distb = new long long[n]{};
    for (int i = 1; i < n; ++i) dista [i] = LLONG_MAX, distb [i] = LLONG_MAX;
    
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> djikstra;
    djikstra.push(PAIR(0, 1)); while (djikstra.size()) {
        std::pair<long long, int> node = djikstra.top(); djikstra.pop();
        if (visiteda [node.second - 1]) continue;
        visiteda [node.second - 1] = 1;
        for (auto& vertex : adj [node.second - 1]) {
            dista [vertex - 1] = MIN(dista [vertex - 1], node.first + MAX(heights [vertex - 1] - heights [node.second - 1], 0));
            djikstra.push(PAIR(dista [vertex - 1], vertex));
        }
    }

    djikstra.push(PAIR(0, 1)); while (djikstra.size()) {
        std::pair<long long, int> node = djikstra.top(); djikstra.pop();
        if (visitedb [node.second - 1]) continue;
        visitedb [node.second - 1] = 1;
        for (auto& vertex : adj [node.second - 1]) {
            distb [vertex - 1] = MIN(distb [vertex - 1], node.first + MAX(heights [node.second - 1] - heights [vertex - 1], 0));
            djikstra.push(PAIR(distb [vertex - 1], vertex));
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) if (dista [i] <= a && distb [i] <= b) ++count;

    std::cout << count;

    return 0;
}