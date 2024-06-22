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
        int a, b, c; std::cin >> a >> b >> c;
        if (a < b && b < c) std::cout << "STAIR\n";
        else if (a < b && b > c) std::cout << "PEAK\n";
        else std::cout << "NONE\n";
    }

    return 0;
}