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
    int n, m, j, mi, ji; std::cin >> n >> m >> j;
    std::vector<int>* adj = new std::vector<int>[n]{};
    int* heights = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> heights [i];
        if (i) {
            if (heights [i] <= heights [i - 1]) {
                adj [i].push_back(i);
            }
            if (heights [i] >= heights [i - 1]) {
                adj [i - 1].push_back(i + 1);
            }
        }
    }

    std::deque<int> search;
    int* infected = new int[n]{};
    for (int i = 0; i < m; ++i) {
        std::cin >> mi;
        search.push_back(mi);
    }

    int* irreplaceable = new int[n]{};
    for (int i = 0; i < j; ++i) {
        std::cin >> ji;
        irreplaceable [ji - 1] = 1;
    }

    while (search.size()) {
        int node = search.front();
        search.pop_front();
        if (infected [node - 1]) continue;
        infected [node - 1] = 1;
        for (auto& vertex : adj [node - 1]) {
            search.push_back(vertex);
        }
    }

    int lost = 0;
    for (int i = 0; i < n; ++i) {
        if (infected [i] && irreplaceable [i]) ++lost;
    }
    
    std::cout << lost;
    return 0;
}