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
    FILE(man);
    int n, w; std::cin >> n >> w;
    int cur = 0;
    int* vals = new int[n]{};
    for (int i = 0; i < w; ++i) std::cin >> vals [i], cur += vals [i];
    int max = cur;
    for (int i = 0; i < (n - w); ++i) {
        std::cin >> vals [i + w];
        cur += vals [i + w];
        cur -= vals [i];
        max = MAX(cur, max);
    }

    std::cout << max;

    return 0;
}