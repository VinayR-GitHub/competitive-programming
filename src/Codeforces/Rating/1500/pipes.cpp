#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int q; std::cin >> q;
    while (q--) {
        int n; std::cin >> n;
        std::string t, b;
        std::cin >> t >> b;
        std::pair<int, int> coord = PAIR(0, 0);
        bool prev = true; // is-left
        bool can = true;
        while (coord.first < n) {
            if (prev) {
                if (coord.second) {
                    if (b [coord.first] < '3') {
                        ++coord.first;
                    } else {
                        coord.second = 0;
                        prev = false;
                    }
                } else {
                    if (t [coord.first] < '3') {
                        ++coord.first;
                    } else {
                        coord.second = 1;
                        prev = false;
                    }
                }
            } else {
                if (coord.second) {
                    if (b [coord.first] < '3') {
                        can = false;
                        goto END;
                    } else {
                        ++coord.first;
                        prev = true;
                    }
                } else {
                    if (t [coord.first] < '3') {
                        can = false;
                        goto END;
                    } else {
                        ++coord.first;
                        prev = true;
                    }
                }
            }
        }
        END:;
        if (!can || !coord.second) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
    return 0;
}