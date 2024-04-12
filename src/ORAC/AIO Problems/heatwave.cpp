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
    FILE(heat);
    int n, h; std::cin >> n >> h;
    int heatwave = 0, wave = 0; int temp;

    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        if (temp >= h) {
            ++heatwave;
        } else {
            wave = MAX(wave, heatwave);
            heatwave = 0;
        }
    }
    wave = MAX(wave, heatwave);

    std::cout << wave;

    return 0;
}