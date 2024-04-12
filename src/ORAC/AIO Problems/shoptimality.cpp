#include <iostream>
#include <array>
#include <limits.h>

int main() {
    int n, m;
    freopen("shopin.txt", "r", stdin);
    freopen("shopout.txt", "w", stdout);

    std::cin >> n >> m;
    auto houses_pos = new int[n]{};
    auto supermarkets_pos = new int[m]{};
    auto supermarkets_price = new int[m]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> houses_pos [i];
    }
    for (int j = 0; j < m; ++j) {
        std::cin >> supermarkets_pos [j];
    }
    for (int k = 0; k < m; ++k) {
        std::cin >> supermarkets_price [k];
    }

    auto low_bads = new int[m]{};
    auto high_bads = new int[m]{};
    for (int a = 0; a < m; ++a) {
        low_bads [a] = supermarkets_price [a] - supermarkets_pos [a];
        high_bads [a] = supermarkets_price [a] + supermarkets_pos [a];
    }

    auto iters = new int[n]{};
    int test_iter = 0;
    for (int it = 0; it < n; ++it) {
        while (houses_pos [it] > supermarkets_pos [test_iter]) {
            if (test_iter == m) {
                break;
            }
            if (test_iter == m - 1) {
                ++test_iter;
                break;
            }
            ++test_iter;
        }
        iters [it] = test_iter - 1;
    }

    auto low_troughs = new int[m]{};
    auto high_troughs = new int[m]{};
    low_troughs [0] = low_bads [0];
    high_troughs [m - 1] = high_bads [m - 1];
    for (int b = 1; b < m; ++b) {
        low_troughs [b] = std::min(low_troughs [b - 1], low_bads [b]);
        high_troughs [m - b - 1] = std::min(high_troughs [m - b], high_bads [m - b - 1]);
    }

    for (int iter = 0; iter < n; ++iter) {
        if (iters [iter] == -1) {
            std::cout << high_troughs [0] - houses_pos [iter] << " ";
            continue;
        } else if (iters [iter] == (m - 1)) {
            std::cout << low_troughs [m - 1] + houses_pos [iter] << " ";
            continue;
        }
        std::cout << std::min(low_troughs [iters [iter]] + houses_pos [iter], high_troughs [iters [iter] + 1] - houses_pos [iter]) << " ";
    }

    return 0;
}