#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int t; std::cin >> t;
    while (t--) {
        char test;
        int a = 0;
        int b = 0;
        for (int i = 0; i < 5; ++i) {
            std::cin >> test;
            if (test == 'A') ++a;
            else ++b;
        }
        if (a > b) std::cout << "A\n";
        else std::cout << "B\n";
    }
    return 0;
}