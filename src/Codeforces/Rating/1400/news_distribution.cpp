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
    std::vector<int>* adj = new std::vector<int>[n]{};
    int ai, xi, ki;
    for (int i = 0; i < m; ++i) {
        std::cin >> ki;
        if (ki == 0) {
            continue;
        } else if (ki == 1) {
            std::cin >> ai;
            continue;
        } else {
            std::cin >> ai;
            for (int i = 0; i < ki - 1; ++i) {
                std::cin >> xi;
                adj [ai - 1].push_back(xi);
                adj [xi - 1].push_back(ai);
            }
        }
    }
    int* visited = new int[n]{};
    int* assoc = new int[n]{};
    std::unordered_map<int, int> tots;
    std::deque<int> bfs;
    for (int i = 0; i < n; ++i) {
        if (visited [i]) continue;
        bfs.push_back(i + 1);
        int count = 0;
        while (bfs.size()) {
            int node = bfs.front();
            bfs.pop_front();
            if (visited [node - 1]) continue;
            visited [node - 1] = 1;
            assoc [node - 1] = i;
            ++count;
            for (auto& vertex : adj [node - 1]) {
                bfs.push_back(vertex);
            }
        }
        tots [i] = count;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << tots [assoc [i]] << ' ';
    }
    return 0;
}