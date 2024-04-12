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
    FILE(hippo);
    int n; std::cin >> n;
    int a, b, c; std::cin >> a >> b >> c;

    std::cout << MAX(n + a - c - 1, MAX(b - a - 1, c - b - 1) + MAX(a - 1, n - c));

    return 0;
}