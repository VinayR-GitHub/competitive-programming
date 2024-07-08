#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    ACCEL();
    int n; std::cin >> n;
    int dim = 1;
    for (int i = 0; i < n; ++i) {
        dim *= 3;
    }
    short* grid = new short[dim * dim]{};
    grid [0] = -11;
    int curlen = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < curlen; ++j) {
            for (int k = 0; k < curlen; ++k) {
                grid [k * dim + j + curlen] = grid [k * dim + j];
                grid [k * dim + j + 2 * curlen] = grid [k * dim + j];
                grid [(k + curlen) * dim + j] = grid [k * dim + j];
                grid [(k + 2 * curlen) * dim + j] = grid [k * dim + j];
                grid [(k + 2 * curlen) * dim + j + curlen] = grid [k * dim + j];
                grid [(k + curlen) * dim + j + 2 * curlen] = grid [k * dim + j];
                grid [(k + 2 * curlen) * dim + j + 2 * curlen] = grid [k * dim + j];
            }
        }
        curlen *= 3;
    }
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            std::cout << static_cast<char>(grid [i * dim + j] + '.');
        }
        std::cout << '\n';
    }
    return 0;
}