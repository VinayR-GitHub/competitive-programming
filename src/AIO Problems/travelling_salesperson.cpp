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
    FILE(sales);
    int a, b, c; std::cin >> a >> b >> c;

    std::cout << (a + b + c - MIN(a, MIN(b, c)));

    return 0;
}