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
        int n, k; std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        int* lettercount = new int[26]{};
        int m = n / k;
        int tot = n;
        for (int i = 0; i < k / 2; ++i) {
            for (int j = 0; j < m; ++j) {
                ++lettercount [s [j * k + i] - 'a'];
            }
            for (int j = 0; j < m; ++j) {
                ++lettercount [s [j * k + k - i - 1] - 'a'];
            }
            int maxop = 0;
            for (int j = 0; j < 26; ++j) {
                maxop = MAX(maxop, lettercount [j]);
                lettercount [j] = 0;
            }
            tot -= maxop;
        }
        if (k & 1) {
            int i = k / 2;
            for (int j = 0; j < m; ++j) {
                ++lettercount [s [j * k + i] - 'a'];
            }
            int maxop = 0;
            for (int j = 0; j < 26; ++j) {
                maxop = MAX(maxop, lettercount [j]);
            }
            tot -= maxop;
        }
        std::cout << tot << '\n';
    }
    return 0;
}