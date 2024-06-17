#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(pair);
    int n; std::cin >> n;
    int* index = new int[n]{};
    int max = 0; int li;
    for (int i = 0; i < 2 * n; ++i) {
        std::cin >> li;
        if (index [li - 1]) {
            max = MAX(max, i - index [li - 1] + 1);
        }
        index [li - 1] = i + 1;
    }

    std::cout << max;
    return 0;
}