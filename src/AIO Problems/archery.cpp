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
    FILE(arch);
    int n, a, b; std::cin >> n >> a >> b; int min_, max_;

    min_ = MIN(MIN(a, b), MAX(a + b - n, 1));
    max_ = MAX(MAX(a, b), MIN(a + b - 1, n));

    std::cout << min_ << " " << max_;

    return 0;
}