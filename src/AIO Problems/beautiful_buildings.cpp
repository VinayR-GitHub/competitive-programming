#include <iostream>
#include <array>
#include <algorithm>

#define FILE freopen
#define MAG std::abs

int main() {
    int n;
    FILE("buildin.txt", "r", stdin);
    FILE("buildout.txt", "w", stdout);

    std::cin >> n;
    int baw = 0;
    auto h_ = new int[n]{};
    auto m_ = new int[n]{};
    std::cin >> h_ [0];
    for (int it = 1; it < n; ++it) {
        std::cin >> h_ [it];
        baw += MAG(h_ [it] - h_ [it - 1]);
    }

    m_ [0] = baw - MAG(h_ [0] - h_ [1]);
    m_ [n - 1] = baw - MAG(h_ [n - 1] - h_ [n - 2]);
    for (int it = 1; it < (n - 1); ++it) {
        m_ [it] = baw - MAG(h_ [it] - h_ [it + 1]) - MAG(h_ [it] - h_ [it - 1]) + MAG(h_ [it + 1] - h_ [it - 1]);
    }

    std::cout << *std::min_element(m_, m_ + n);

    return 0;
}