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
        std::string x; std::cin >> x;
        if (x [0] != 49) {
            std::cout << "NO\n";
            goto NEXT;
        }
        for (int i = 1; i < x.length() - 1; ++i) {
            if (x [i] == 48) {
                std::cout << "NO\n";
                goto NEXT;
            }
        }
        if (x [x.length() - 1] == 57) {
            std::cout << "NO\n";
            goto NEXT;
        }
        std::cout << "YES\n";
        NEXT:
    }

    return 0;
}