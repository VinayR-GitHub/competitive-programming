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
        long long num = 0;
        num += a;
        num += b / 3;
        if (c < 3 - b % 3 && b % 3) {
            std::cout << "-1\n";
            continue;
        }
        num += (c + b % 3) / 3;
        num += (c + b % 3) % 3 != 0;
        std::cout << num << '\n';
    }

    return 0;
}