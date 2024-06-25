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
        std::string aim; std::cin >> aim;
        int count = 0;
        std::vector<int> loc;
        for (int i = 0; i < n; ++i) {
            if (aim [i] == 49) {
                ++count;
                loc.push_back(i);
            }
        }

        if (count & 1) {
            std::cout << "NO\n";
            goto NEXT;
        }
        if (count == 2) {
            if (loc [0] == loc [1] - 1) {
                std::cout << "NO\n";
                goto NEXT;
            }
        }

        std::cout << "YES\n";
        NEXT:;
    }

    return 0;
}