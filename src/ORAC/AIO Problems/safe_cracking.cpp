#include <iostream>
#include <array>

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
    FILE(safe);
    int a, b; std::cin >> a >> b;
    int* a_ = new int[a]{}; for (int i = 0; i < a; ++i) std::cin >> a_ [i];
    int* b_ = new int[b]{}; for (int i = 0; i < b; ++i) std::cin >> b_ [i];

    int k;

    for (int i = 0; i < (a - b + 1); ++i) {
        int target = a_ [i] - b_ [0]; bool maybe = true;
        for (int it = 1; it < b; ++it) {
            if (a_ [i + it] - b_ [it] != target) {
                maybe = false; break;
            }
        }
        if (maybe == false) {
            continue;
        } else {
            if (target >= 0) {
                k = target;
                break;
            } else {
                continue;
            }
        }
    }

    for (int i = 0; i < a; ++i) std::cout << (a_ [i] - k) << '\n';

    return 0;
}