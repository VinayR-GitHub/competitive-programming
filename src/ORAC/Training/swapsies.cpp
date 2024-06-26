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
    FILE(swaps);
    int n; std::cin >> n;
    double* a = new double[n]{};

    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
    }

    for (int i = 0; i < n; ++i) {
        double max = -1001;
        int maxiter = 0;
        for (int j = i; j < n; ++j) {
            if (a [j] > max) {
                max = a [j];
                maxiter = j;
            }
        }

        if (i != maxiter) {
            std::swap(a [i], a [maxiter]);
            std::cout << i + 1 << ' ';
            std::cout << maxiter + 1 << '\n';
        }
    }

    std::cout << "all sorted";
    return 0;
}