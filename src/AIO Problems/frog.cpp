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
    FILE(frog);
    int n; std::cin >> n;
    auto h_ = new int[n]{}, l_ = new int[n]{}, r_ = new int[n]{}; std::cin >> h_ [0];
    l_ [0] = h_ [0]; for (int i = 1; i < n; ++i) std::cin >> h_ [i], l_ [i] = MIN(l_ [i - 1], h_ [i]);
    r_ [n - 1] = h_ [n - 1]; for (int i = (n - 2); i >= 0; --i) r_ [i] = MIN(r_ [i + 1], h_ [i]);
    int boeing747 = 0;
    for (int i = 1; i < (n - 1); ++i) {
        if (h_ [i] > l_ [i - 1] && h_ [i] > r_ [i + 1]) {
            boeing747 = MAX(boeing747, (2 * h_ [i]) - l_ [i - 1] - r_ [i + 1]);
        }
    }

    std::cout << boeing747;

    return 0;
}