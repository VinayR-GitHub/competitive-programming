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
    FILE(ticket);
    int ac, at, bc, bt, d; std::cin >> ac >> at >> bc >> bt >> d;
    int* d_ = new int[d]{}; for (int i = 0; i < d; ++i) std::cin >> d_ [i];
    int* m_ = new int[d + 1]{};
    m_ [0] = 0;
    for (int i = 1; i < d + 1; ++i) {
        m_ [i] = INT_MAX;
        for (int j = i - 1; j >= 0; --j) {
            int delta_t = d_ [i - 1] - d_ [j];
            if (delta_t < at) m_ [i] = MIN(m_ [i], m_ [j] + ac);
            if (delta_t < bt) m_ [i] = MIN(m_ [i], m_ [j] + bc);
        }
    }
    
    std::cout << m_ [d];

    return 0;
}