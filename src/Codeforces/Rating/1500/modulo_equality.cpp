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
    int* a = new int[n]{};
    int* b = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b [i];
    }
    std::sort(a, a + n);
    std::sort(b, b + n);
    int minx = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int x = b [i] - a [0] + m;
        x %= m;
        int* c = new int[n]{};
        for (int j = 0; j < n; ++j) {
            c [j] = a [j] + x;
            c [j] %= m;
        }
        std::sort(c, c + n);
        bool can = true;
        for (int j = 0; j < n; ++j) {
            if (c [j] != b [j]) {
                can = false;
                break;
            }
        }
        if (can) {
            minx = MIN(minx, x);
        }
    }
    std::cout << minx;
    return 0;
}