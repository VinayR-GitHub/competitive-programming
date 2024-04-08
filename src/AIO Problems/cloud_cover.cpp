#include <iostream>
#include <array>
#include <climits>

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
    FILE(cloud);
    int n, k; std::cin >> n >> k;
    auto dists = new int[n - 1]{};
    for (int i = 1; i < n; ++i) std::cin >> dists [i - 1];

    int traversal = 0;
    for (int i = 0; i < k; ++i) traversal += dists [i];
    int minimum = traversal;
    for (int i = 0; i < (n - k - 1); ++i) minimum = MIN(minimum, traversal - dists [i] + dists [i + k]), traversal -= dists [i], traversal += dists [i + k];

    std::cout << minimum;

    return 0;
}