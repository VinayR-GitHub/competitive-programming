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
        int a, b, c, d; std::cin >> a >> b >> c >> d;
        if (b == 12) b = 0;
        if (c == 12) c = 0;
        if (d == 12) d = 0;
        int count = 0;
        for (int i = (a + 1) % 12; i % 12 != b; ++i) {
            if (i % 12 == c || i % 12 == d) ++count;
        }
        if (count == 1) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}