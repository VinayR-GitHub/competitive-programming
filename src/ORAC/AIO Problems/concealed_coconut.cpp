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
    FILE(coco);
    int ix, iy, id, cx, cy, cd; std::cin >> ix >> iy >> id >> cx >> cy >> cd;

    // Is the circle internally contained.
    if (id > cd) {
        if (id > cd + std::sqrt(pow((iy - cy), 2) + pow((ix - cx), 2))) {
            std::cout << "no";
            return 0;
        }
    }
    if (cd > id) {
        if (cd > id + std::sqrt(pow((iy - cy), 2) + pow((ix - cx), 2))) {
            std::cout << "no";
            return 0;
        }
    }

    // Do the circles intersect.
    if ((cx - ix) * (cx - ix) + (cy - iy) * (cy - iy) <= (id + cd) * (id + cd)) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }

    return 0;
}