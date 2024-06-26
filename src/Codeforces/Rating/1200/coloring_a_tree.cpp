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
    int pi, ci;

    std::vector<int>* adj = new std::vector<int>[n]{};
    for (int i = 1; i < n; ++i) {
        std::cin >> pi;
        adj [pi - 1].push_back(i + 1);
    }

    int* c = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> c [i];
    }

    int* m = new int[n]{};
    for (int i = 0; i < n; ++i) {
        m [i] = c [0];
    }

    int cost = 1;
    std::deque<int> bfs;
    bfs.push_back(1);

    std::function<void(int, int)> paint;
    paint = [&](int point, int col)->void {
        m [point - 1] = col;
        if (c [point - 1] != col) return;
        for (auto& vertex : adj [point - 1]) {
            paint(vertex, col);
        }
    };

    while (bfs.size()) {
        int node = bfs.front();
        bfs.pop_front();

        for (auto& vertex : adj [node - 1]) {
            bfs.push_back(vertex);
        }
        if (m [node - 1] == c [node - 1]) continue;
        
        ++cost;
        paint(node, c [node - 1]);
    }
    
    std::cout << cost;
    return 0;
}