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
    FILE(lsc);
    int n, l; std::cin >> n >> l;
    auto pos = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> pos [i];
    auto ord = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> ord [i];

    int minbound = 1; int maxbound = l;
    for (int b = 0; b < (n - 1); ++b) {
        int mid = (pos [ord [b] - 1] + pos [ord [b + 1] - 1]) >> 1;
        if (pos [ord [b + 1] - 1] > pos [ord [b] - 1]) {
            maxbound = MIN(maxbound, mid);
        } else {
            minbound = MAX(minbound, mid);
        }
    }

    if (maxbound < minbound) {
        std::cout << "-1";
    } else {
        std::cout << minbound;
    }
    
    return 0;
}