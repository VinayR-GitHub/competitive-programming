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
    FILE(alien);
    int n, w; std::cin >> n >> w; int temp; int bound = 0;
    int cur = 0; int* is_human_here = new int[(int) 1e6+1]{};
    for (int i = 0; i < n; ++i) std::cin >> temp, ++is_human_here [temp], bound = MAX(bound, temp);
    for (int i = 0; i < w; ++i) cur += is_human_here [i];
    int max = cur;
    for (int i = 0; i < (bound - w + 1); ++i) {
        cur -= is_human_here [i];
        cur += is_human_here [i + w];
        max = MAX(cur, max);
    }

    std::cout << max;

    return 0;
}