#include <iostream>
#include <cmath>

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
    FILE(probe);
    int r, c, pr, pc, fr, fc, q; std::cin >> r >> c >> pr >> pc >> fr >> fc >> q;
    long long probe_dist, fiss_dist; int ri, ci;
    if (abs(pr - fr) == abs(pc - fc)) {
        while (q--) {
            std::cin >> ri >> ci;
            probe_dist = ((long long) MAG(ri - pr) *(long long)  MAG(ri - pr)) + ((long long) MAG(ci - pc) * (long long) MAG(ci - pc));
            fiss_dist = ((long long) MAG(ri - fr) * (long long) MAG(ri - fr)) + ((long long) MAG(ci - fc) * (long long) MAG(ci - fc));
            if (probe_dist > fiss_dist) {
                std::cout << "LAVA" << '\n';
            } else if (probe_dist < fiss_dist) {
                std::cout << "WATER" << '\n';
            } else {
                std::cout << "MOUNTAINS" << '\n';
            }
        }
    } else {
        while (q--) {
            std::cin >> ri >> ci;
            probe_dist = MAG(ri - pr) + MAG(ci - pc);
            fiss_dist = MAG(ri - fr) + MAG(ci - fc);
            if (probe_dist > fiss_dist) {
                std::cout << "LAVA" << '\n';
            } else if (probe_dist < fiss_dist) {
                std::cout << "WATER" << '\n';
            } else {
                std::cout << "MOUNTAINS" << '\n';
            }
        }
    }

    return 0;
}