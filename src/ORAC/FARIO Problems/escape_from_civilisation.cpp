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
    int w, h; std::cin >> w >> h;
    int* dist = new int[w * h]{};
    std::deque<std::pair<int, int>> bfs;
    char is_civ;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cin >> is_civ;
            if (is_civ == '1') {
                bfs.push_back(PAIR(i, j));
            }
        }
    }

    for (int i = 1; bfs.size(); ++i) {
        int num = bfs.size();
        while (num--) {
            std::pair<int, int> node = bfs.front();
            bfs.pop_front();
            if (dist [node.first * w + node.second]) continue;
            dist [node.first * w + node.second] = i;
            if (node.first) {
                bfs.push_back(PAIR(node.first - 1, node.second));
            }
            if (node.second) {
                bfs.push_back(PAIR(node.first, node.second - 1));
            }
            if (node.first != h - 1) {
                bfs.push_back(PAIR(node.first + 1, node.second));
            }
            if (node.second != w - 1) {
                bfs.push_back(PAIR(node.first, node.second + 1));
            }
        }
    }

    int max = 0;
    for (int i = 0; i < w * h; ++i) {
        max = MAX(max, dist [i]);
    }

    std::cout << max - 1;
    return 0;
}