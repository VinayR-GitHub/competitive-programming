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
    FILE(qsort);
    int n; std::cin >> n;
    std::vector<int>* adj = new std::vector<int>[n + 1]{};
    int ti, ji, xi, yi;
    for (int i = 0; i < n; ++i) {
        std::cin >> ti;
        switch (ti) {
            case 1:
                adj [i].push_back(i + 1);
                break;
            case 2:
                std::cin >> ji;
                adj [i].push_back(ji - 1);
                break;
            case 3:
                std::cin >> xi >> yi;
                adj [i].push_back(xi - 1);
                adj [i].push_back(yi - 1);
                break;
        }
    }
    if (ti == 1) {
        adj [n - 1] = {};
    }

    int* visited = new int[n]{};
    int count = 0;
    std::deque<int> search;
    search.push_back(0);
    while (search.size()) {
        int node = search.front();
        search.pop_front();
        if (visited [node]) continue;
        visited [node] = 1; ++count;
        for (auto& vertex : adj [node]) {
            search.push_back(vertex);
        }
    }

    std::cout << n - count;
    return 0;
}