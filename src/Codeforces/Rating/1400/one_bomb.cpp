#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int n, m; std::cin >> n >> m;
    int* is = new int[n * m]{};
    int* rowtots = new int[n]{};
    int* coltots = new int[m]{};
    int walls = 0;
    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> c;
            if (c == '*') {
                ++rowtots [i];
                ++coltots [j];
                is [i * m + j] = 1;
                ++walls;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (rowtots [i] + coltots [j] - is [i * m + j] == walls) {
                std::cout << "YES\n" << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
    }
    std::cout << "NO";
    return 0;
}