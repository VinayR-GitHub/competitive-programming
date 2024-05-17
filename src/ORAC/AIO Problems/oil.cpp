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
    FILE(oil);
    int r, c, k; std::cin >> r >> c >> k;
    std::pair<int, int> src;
    char* map = new char[r * c]{}; for (int i = 0; i < r * c; ++i) {
        std::cin >> map [i];
        if (map [i] == '$') src = PAIR(i / c, i % c);
    }
    int* visited = new int[r * c]{}; std::vector<std::pair<int, int>> curlocse = {src}, curlocso = {};

    for (int i = 0; i <= k; ++i) {
        if (i & 1) {
            for (auto& pt : curlocso) {
                if (!visited [pt.first * c + pt.second]) {
                    visited [pt.first * c + pt.second] = 1;
                    map [pt.first * c + pt.second] = '*';
                    if (pt.first) {
                        if (map [(pt.first - 1) * c + pt.second] == '.') curlocse.emplace_back(PAIR(pt.first - 1, pt.second));
                    }
                    if (pt.second) {
                        if (map [pt.first * c + pt.second - 1] == '.') curlocse.emplace_back(PAIR(pt.first, pt.second - 1));
                    }
                    if (pt.first != (r - 1)) {
                        if (map [(pt.first + 1) * c + pt.second] == '.') curlocse.emplace_back(PAIR(pt.first + 1, pt.second));
                    }
                    if (pt.second != (c - 1)) {
                        if (map [pt.first * c + pt.second + 1] == '.') curlocse.emplace_back(PAIR(pt.first, pt.second + 1));
                    }
                }
            }
            curlocso.clear();
        } else {
            for (auto& pt : curlocse) {
                if (!visited [pt.first * c + pt.second]) {
                    visited [pt.first * c + pt.second] = 1;
                    map [pt.first * c + pt.second] = '*';
                    if (pt.first) {
                        if (map [(pt.first - 1) * c + pt.second] == '.') curlocso.emplace_back(PAIR(pt.first - 1, pt.second));
                    }
                    if (pt.second) {
                        if (map [pt.first * c + pt.second - 1] == '.') curlocso.emplace_back(PAIR(pt.first, pt.second - 1));
                    }
                    if (pt.first != (r - 1)) {
                        if (map [(pt.first + 1) * c + pt.second] == '.') curlocso.emplace_back(PAIR(pt.first + 1, pt.second));
                    }
                    if (pt.second != (c - 1)) {
                        if (map [pt.first * c + pt.second + 1] == '.') curlocso.emplace_back(PAIR(pt.first, pt.second + 1));
                    }
                }
            }
            curlocse.clear();
        }
    }

    map [src.first * c + src.second] = '$';
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << map [i * c + j];
        }
        std::cout << '\n';
    }

    return 0;
}