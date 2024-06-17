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
    FILE(goss);
    int n; std::cin >> n;
    std::vector<int>* adj = new std::vector<int>[n]{};
    int ai, bi;
    while (true) {
        std::cin >> ai >> bi;
        if (ai == -1) break;
        adj [ai].push_back(bi);
        adj [bi].push_back(ai);
    }
    int* visited = new int[n]{};
    int group = 1;
    std::deque<int> bfs;
    for (int i = 0; i < n; ++i) {
        if (visited [i]) continue;
        bfs.push_back(i);
        while (bfs.size()) {
            int node = bfs.front();
            bfs.pop_front();
            if (visited [node]) continue;
            visited [node] = group;
            for (auto& vertex : adj [node]) {
                bfs.push_back(vertex);
            }
        }
        ++group;
    }

    int pi, qi;
    while (true) {
        std::cin >> pi >> qi;
        if (pi == -1) break;
        if (visited [pi] == visited [qi]) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }

    return 0;
}