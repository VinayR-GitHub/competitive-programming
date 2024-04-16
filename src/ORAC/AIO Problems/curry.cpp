#include <iostream>
#include <array>
#include <algorithm>

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
    FILE(curry);
    int c, r, v; std::cin >> c >> r >> v;
    std::pair<int, int>* crv = new std::pair<int, int>[3]{}; crv [0] = PAIR(c, 1); crv [1] = PAIR(r, 2); crv [2] = PAIR(v, 3);
    int x = 0, y = 0, z = 0;
    while (true) {
        std::sort(crv, crv + 3);
        if (!crv [1].first) {
            break;
        }
        switch (crv [0].second) {
            case 1:
                ++x;
                --crv [1].first; --crv [2].first;
                break;
            case 2:
                ++y;
                --crv [1].first; --crv [2].first;
                break;
            case 3:
                ++z;
                --crv [1].first; --crv [2].first;
                break;
        }
    }

    std::cout << x << " " << y << " " << z;

    return 0;
}