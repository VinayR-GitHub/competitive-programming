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
    int n; std::cin >> n; int ai, bi;
    if (n == 1) {
        std::cout << 1;
        return 0;
    }

    std::vector<int>* adj = new std::vector<int>[n]{};
    for (int i = 1; i < n; ++i) std::cin >> ai >> bi, adj [ai - 1].push_back(bi), adj [bi - 1].push_back(ai);

    int* visited = new int[n]{};
    std::deque<int> bfs; bfs.push_back(1);
    int iter = -1;
    while (bfs.size()) {
        int num = bfs.size();
        while (num--) {
            int node = bfs.front(); bfs.pop_front();
            if (visited [node - 1]) continue;
            visited [node - 1] = 1;
            for (auto& vertex : adj [node - 1]) bfs.push_back(vertex);
        }
        ++iter;
    }

    std::cout << 2 * n - iter;

    return 0;
}