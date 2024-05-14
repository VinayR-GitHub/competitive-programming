#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(surf);
    int r, c; std::cin >> r >> c;
    char* crd = new char[r * c]{}; for (int i = 0; i < r * c; ++i) std::cin >> crd [i];

    int* visited = new int[r * c]{}; std::deque<std::pair<int, int>> loci; loci.push_back(PAIR(r - 1, c - 1));
    int count = 0;
    while (loci.size()) {
        std::pair<int, int> pos = loci.front();
        loci.pop_front();
        int ps = pos.first * c + pos.second;
        if (!visited [ps]) {
            visited [ps] = 1; ++count;
            if (pos.first) {
                if (crd [ps - c] == 'v') loci.push_back(PAIR(pos.first - 1, pos.second));
            }
            if (pos.second) {
                if (crd [ps - 1] == '>') loci.push_back(PAIR(pos.first, pos.second - 1));
            }
        }
    }

    std::cout << (r * c - count);

    return 0;
}