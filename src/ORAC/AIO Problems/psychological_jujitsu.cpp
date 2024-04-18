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
    FILE(psych);
    int* bids = new int[13]{}; int temp; for (int i = 0; i < 13; ++i) std::cin >> temp, bids [temp - 1] = i + 1;
    int cur = 91 - 2 * bids [12];
    int max = cur;

    for (int i = 12; i > 0; --i) {
        cur += bids [i];
        cur -= (2 * bids [i - 1]);
        max = MAX(cur, max);
    }

    // It's always possible.
    std::cout << max;

    return 0;
}