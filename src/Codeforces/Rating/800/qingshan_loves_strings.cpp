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
        int n, m; std::cin >> n >> m;
        std::string ss, st; std::cin >> ss >> st;
        bool is = true;
        std::pair<bool, bool> or01 = PAIR(false, false);
        for (int i = 0; i < n - 1; ++i) {
            if (ss [i] == ss [i + 1]) {
                is = false;
                (ss [i] == 48 ? or01.first : or01.second) = true;
            }
        }
        if (is) {
            std::cout << "YES\n";
            goto NEXT;
        }
        if (st [0] != st [st.length() - 1]) {
            std::cout << "NO\n";
            goto NEXT;
        }
        is = true;
        for (int i = 0; i < m - 1; ++i) {
            if (st [i] == st [i + 1]) is = false;
        }
        if (!is) {
            std::cout << "NO\n";
            goto NEXT;
        }
        if (or01.first && st [0] == 48 || or01.second && st [0] == 49) {
            std::cout << "NO\n";
            goto NEXT;
        }
        std::cout << "YES\n";

        NEXT:;
    }

    return 0;
}