#include <iostream>

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
    FILE(chimp);
    int x, y; std::cin >> x >> y;

    int cursquare = MAX(MAG(x), MAG(y));
    if (!cursquare) {
        std::cout << 0;
        return 0;
    }
    int curring_cur = ((2 * cursquare) - 1) * ((2 * cursquare) - 1);
    std::pair<int, int> curcoord = PAIR(cursquare, 1 - cursquare);
    while (true) {
        if (curcoord == PAIR(x, y)) {
            break;
        }
        ++curring_cur;
        if (curcoord.second == -cursquare) {
            ++curcoord.first;
        } else if (curcoord.first == -cursquare) {
            --curcoord.second;
        } else if (curcoord.second == cursquare) {
            --curcoord.first;
        } else if (curcoord.first == cursquare) {
            ++curcoord.second;
        }
    }

    std::cout << curring_cur;

    return 0;
}