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
        int* a = new int[n]{};
        for (int i = 0; i < n; ++i) std::cin >> a [i];
        if (a [0] == a [n - 1]) {
            std::cout << "NO\n";
            continue;
        }
        std::cout << "YES\nRB";
        for (int i = 0; i < n - 2; ++i) std::cout << 'R';
        std::cout << '\n';
    }

    return 0;
}