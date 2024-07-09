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
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
        }
        std::string res = "";
        int* upto = new int[n]{};
        for (int i = 0; i < n; ++i) {
            res += static_cast<char>(upto [a [i]] + 'a');
            ++upto [a [i]];
        }
        std::cout << res << '\n';
    }
    return 0;
}