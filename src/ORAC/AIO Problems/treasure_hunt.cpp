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
    FILE(cave);
    int h, w; std::cin >> h >> w;
    int robots = 1; char temp;
    int* cave = new int[h * w]{}; for (int i = 0; i < (h * w); ++i) std::cin >> temp, cave [i] = (temp == '#') ? 0 : 1;
    for (int j = 0; j < h; ++j) {
        bool top = j == 0; bool bottom = j == (h - 1);
        for (int i = 0; i < w; ++i) {
            bool left = i == 0; bool right = i == (w - 1);
            if (!cave [j * w + i]) {
                continue;
            }
            int num = 0;
            if (!top) {
                if (cave [(j - 1) * w + i] == 1) {
                    ++num;
                }
            }
            if (!bottom) {
                if (cave [(j + 1) * w + i] == 1) {
                    ++num;
                }
            }
            if (!left) {
                if (cave [j * w + i - 1] == 1) {
                    ++num;
                }
            }
            if (!right) {
                if (cave [j * w + i + 1] == 1) {
                    ++num;
                }
            }
            if (num == 3) {
                ++robots;
            }
            if (num == 4) {
                robots += 2;
            }
        }
    }
    if (cave [w] && cave [1] && h != 1 && w != 1) {
        ++robots;
    }

    std::cout << robots;

    return 0;
}