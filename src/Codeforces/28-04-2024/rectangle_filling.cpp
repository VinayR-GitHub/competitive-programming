#include <iostream>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;
    while (t--) {
        int n, m; std::cin >> n >> m;
        int left = 0, right = 0, top = 0, bottom = 0;
        char temp;

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                bool l = i == 0;
                bool r = i == (m - 1);
                bool t = j == 0;
                bool b = j == (n - 1);
                std::cin >> temp;
                if (temp == 'B') {
                    if (l) ++left;
                    if (r) ++right;
                    if (t) ++top;
                    if (b) ++bottom;
                }
            }
        }

        if (left && right && bottom && top) {
            std::cout << "YES\n";
        } else if (left < n && right < n && bottom < m && top < m) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}