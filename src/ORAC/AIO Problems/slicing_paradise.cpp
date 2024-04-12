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
    FILE(slice);
    int n; std::cin >> n;
    int max = 1, cur = 1; int temp;
    int* times = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> temp, times [temp - 1] = i + 1;
    int* parks = new int[n + 2]{}; parks [0] = 1; parks [n + 1] = 1;
    for (int i = 0; i < n; ++i) {
        parks [times [i]] = 1;
        if (!parks [times [i] - 1] && !parks [times [i] + 1]) ++cur;
        if (parks [times [i] - 1] && parks [times [i] + 1]) --cur;
        max = MAX(cur, max);
    }

    std::cout << max;
    
    return 0;
}