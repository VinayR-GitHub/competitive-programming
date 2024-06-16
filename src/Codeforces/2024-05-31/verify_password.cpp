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
        int n; std::cin >> n;
        std::string password; std::cin >> password;
        char curchar = password [0];
        bool is = true;
        for (int i = 1; i < n; ++i) {
            if (password [i] < curchar) {
                is = false;
                break;
            }
            curchar = password [i];
        }
        std::cout << (is ? "YES\n" : "NO\n");
    }

    return 0;
}