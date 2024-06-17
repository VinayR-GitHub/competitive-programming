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
    int ai, bi;
    for (int i = 0; i < m; ++i) {
        std::cin >> ai >> bi;
        adj [ai - 1].push_back(bi);
        adj [bi - 1].push_back(ai);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << adj [i].size();
        for (auto& vertex : adj [i]) {
            std::cout << ' ' << vertex;
        }
        std::cout << '\n';
    }
    return 0;
}