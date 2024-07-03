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
    std::vector<int>* adj = new std::vector<int>[n]{};
    int ui, vi;
    for (int i = 0; i < m; ++i) {
        std::cin >> ui >> vi;
        adj [ui - 1].push_back(vi);
        adj [vi - 1].push_back(ui);
    }
    int* visited = new int[n]{};
    std::deque<int> bfs;
    bfs.push_back(1);
    int num = 1;
    while (bfs.size()) {
        int len = bfs.size();
        while (len--) {
            int node = bfs.front();
            bfs.pop_front();
            if (visited [node - 1]) continue;
            visited [node - 1] = num;
            for (auto& vertex : adj [node - 1]) {
                bfs.push_back(vertex);
            }
        }
        ++num;
    }
    int maxvert;
    int maxlen = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (visited [i] > maxlen) {
            maxlen = visited [i];
            maxvert = i + 1;
        }
        visited [i] = 0;
    }
    bfs.push_back(maxvert);
    num = 1;
    while (bfs.size()) {
        int len = bfs.size();
        while (len--) {
            int node = bfs.front();
            bfs.pop_front();
            if (visited [node - 1]) continue;
            visited [node - 1] = num;
            for (auto& vertex : adj [node - 1]) {
                bfs.push_back(vertex);
            }
        }
        ++num;
    }
    maxlen = INT_MIN;
    for (int i = 0; i < n; ++i) {
        maxlen = MAX(maxlen, visited [i] - 1);
    }
    std::cout << maxlen;
    return 0;
}