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
        int count = 0;
        char face;
        for (int i = 0; i < n; ++i) {
            std::cin >> face;
            count += face == 'U';
        }
        if (count & 1) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}