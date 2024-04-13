#include <iostream>

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
    FILE(post);
    int n; std::cin >> n;
    int ind = 0;
    int curl, curr; int xtemp, wtemp; std::cin >> xtemp >> wtemp; curl = xtemp; curr = xtemp + wtemp;
    for (int pos = 1; pos < n; ++pos) {
        int disp, w; std::cin >> disp >> w;
        if (disp < curl || (disp < curr && (disp + w) > curl)) {
            curl = disp;
            curr = disp + w;
            ind = pos;
        }
    }

    ++ind;
    std::cout << ind;

    return 0;
}