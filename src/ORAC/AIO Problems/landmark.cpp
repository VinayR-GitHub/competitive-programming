#include <iostream>
#include <array>

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
    FILE(land);
    int r, c; std::cin >> r >> c;
    char* blocks = new char[r * c]{};
    std::pair<std::pair<int, int>, std::pair<int, int>> curgoodsh, curgoodsv;
    // Horizontal
    int hmax = 0, vmax = 0;
    int cur = 0; for (int j = 0; j < r; ++j) {
        for (int i = 0; i < c; ++i) {
            std::cin >> blocks [j * c + i];
            if (blocks [j * c + i] == '.') {
                ++cur;
            } else {
                if (cur > hmax) {
                    curgoodsh = PAIR(PAIR(i - cur, j), PAIR(i - 1, j));
                    hmax = cur;
                }
                cur = 0;
            }
        }
        if (cur > hmax) {
            curgoodsh = PAIR(PAIR(c - cur, j), PAIR(c - 1, j));
            hmax = cur;
        }
        cur = 0;
    }
    // Vertical
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            if (blocks [j * c + i] == '.') {
                ++cur;
            } else {
                if (cur > vmax) {
                    curgoodsv = PAIR(PAIR(i, j - cur), PAIR(i, j - 1));
                    vmax = cur;
                }
                cur = 0;
            }
        }
        if (cur > vmax) {
            curgoodsv = PAIR(PAIR(i, r - cur), PAIR(i, r - 1));
            vmax = cur;
        }
        cur = 0;
    }
    
    std::cout << ((hmax >= vmax) ? (curgoodsh.first.second + 1) : (curgoodsv.first.second + 1)) << " " << ((hmax >= vmax) ? (curgoodsh.first.first + 1) : (curgoodsv.first.first + 1)) << " " << ((hmax >= vmax) ? (curgoodsh.second.second + 1) : (curgoodsv.second.second + 1)) << " " << ((hmax >= vmax) ? (curgoodsh.second.first + 1) : (curgoodsv.second.first + 1));

    return 0;
}