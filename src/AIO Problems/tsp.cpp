#include <iostream>
#include <limits.h>
#include <array>

#define MAX std::max

int main() {
    int n;
    int cur = INT_MIN;
    bool can_do = true;
    freopen("tspin.txt", "r", stdin);
    freopen("tspout.txt", "w", stdout);

    std::cin >> n;
    auto l_ = new int[n]{};
    auto r_ = new int[n]{};
    for (int i = 0; i < n; ++i) {
        int l;
        std::cin >> l;
        l_ [i] = l;
    }
    for (int j = 0; j < n; ++j) {
        int r;
        std::cin >> r;
        r_ [j] = r;
    }

    for (int k = 0; k < n; ++k) {
        if (r_ [k] < cur) {
            can_do = false;
            break;
        }
        cur = MAX(cur, l_ [k]);
    }

    std::cout << ((can_do) ? "YES" : "NO");

    return 0;
}