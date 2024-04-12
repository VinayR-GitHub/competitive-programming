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
    FILE(wet);
    int cap = 0;
    int temp; for (int i = 0; i < 8; ++i) std::cin >> temp, cap += temp, cap = MAX(0, cap - 10);

    std::cout << cap;

    return 0;
}