#include <bits/stdc++.h>

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
    FILE(rest);
    int n; std::cin >> n;
    int* dlgs = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> dlgs [i];
    int m; std::cin >> m;
    int* rsts = new int[m]{}; for (int i = 0; i < m; ++i) std::cin >> rsts [i];

    std::sort(dlgs, dlgs + n, std::greater<int>());

    int count = 0;
    for (int i = 0; i < n; ++i) count += dlgs [i];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!dlgs [j]) ++rsts [i];
            else --dlgs [j], --count;
        }
    }

    std::cout << count;

    return 0;
}