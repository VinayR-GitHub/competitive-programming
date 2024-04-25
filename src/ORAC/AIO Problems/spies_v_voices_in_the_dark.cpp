#include <iostream>
#include <array>
#include <vector>

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
    FILE(spies); int temp;
    int* injean = new int[10000001]{};
    int time = 0;
    int j, g; std::cin >> j; for (int i = 0; i < j; ++i) {
        int in, ot; std::cin >> in >> ot;
        for (int l = in; l < ot; ++l) ++injean [l];
    }
    std::cin >> g; for (int i = 0; i < g; ++i) {
        int in, ot; std::cin >> in >> ot;
        for (int l = in; l < ot; ++l) {
            if (injean [l]) ++time;
        }
    }

    std::cout << time;

    return 0;
}