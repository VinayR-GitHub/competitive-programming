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
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        int maxx = INT_MIN;
        int minx = INT_MAX;
        int maxy = INT_MIN;
        int miny = INT_MAX;
        int xi, yi;
        for (int i = 0; i < n; ++i) {
            std::cin >> xi >> yi;
            maxx = MAX(maxx, xi);
            minx = MIN(minx, xi);
            maxy = MAX(maxy, yi);
            miny = MIN(miny, yi);
        }
        if (minx <= 0 && maxx <= 0) {
            std::cout << "YES\n";
        } else if (minx >= 0 && maxx >= 0) {
            std::cout << "YES\n";
        } else if (miny <= 0 && maxy <= 0) {
            std::cout << "YES\n";
        } else if (miny >= 0 && maxy >= 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}