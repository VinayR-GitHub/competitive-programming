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
    FILE(mouse);
    int* x_ = new int[8]{}; int* y_ = new int[8]{};
    for (int i = 0; i < 8; ++i) std::cin >> x_ [i], std::cin >> y_ [i];
    std::sort(x_, x_ + 8); std::sort(y_, y_ + 8);
    if (x_ [0] == x_ [3]) {
        std::cout << 'W';
    } else if (x_ [4] == x_ [7]) {
        std::cout << 'E';
    } else if (y_ [0] == y_ [3]) {
        std::cout << 'S';
    } else {
        std::cout << 'N';
    }

    return 0;
}