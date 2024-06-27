#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    std::string a, b, c, d; char ph;
    std::cin >> ph >> ph >> a;
    std::cin >> ph >> ph >> b;
    std::cin >> ph >> ph >> c;
    std::cin >> ph >> ph >> d;
    int great = 0;
    if (a.length() >= 2 * b.length() && a.length() >= 2 * c.length() && a.length() >= 2 * d.length()) {
        ++great;
    } else if (2 * a.length() <= b.length() && 2 * a.length() <= c.length() && 2 * a.length() <= d.length()) {
        ++great;
    }
    if (b.length() >= 2 * a.length() && b.length() >= 2 * c.length() && b.length() >= 2 * d.length()) {
        great += 2;
    } else if (2 * b.length() <= a.length() && 2 * b.length() <= c.length() && 2 * b.length() <= d.length()) {
        great += 2;
    }
    if (c.length() >= 2 * b.length() && c.length() >= 2 * a.length() && c.length() >= 2 * d.length()) {
        great += 4;
    } else if (2 * c.length() <= b.length() && 2 * c.length() <= a.length() && 2 * c.length() <= d.length()) {
        great += 4;
    }
    if (d.length() >= 2 * b.length() && d.length() >= 2 * c.length() && d.length() >= 2 * a.length()) {
        great += 8;
    } else if (2 * d.length() <= b.length() && 2 * d.length() <= c.length() && 2 * d.length() <= a.length()) {
        great += 8;
    }
    if (__builtin_popcount(great) == 1) {
        int num = -1;
        while (great) {
            great >>= 1;
            ++num;
        }
        std::cout << static_cast<char>('A' + num);
    } else {
        std::cout << 'C';
    }
    return 0;
}