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
        int n, m; std::cin >> n >> m;
        std::string problems; std::cin >> problems;
        int* abc = new int[7]{};
        for (int i = 0; i < n; ++i) {
            switch (problems [i]) {
                case 'A':
                    ++abc [0];
                    break;
                case 'B':
                    ++abc [1];
                    break;
                case 'C':
                    ++abc [2];
                    break;
                case 'D':
                    ++abc [3];
                    break;
                case 'E':
                    ++abc [4];
                    break;
                case 'F':
                    ++abc [5];
                    break;
                case 'G':
                    ++abc [6];
                    break;
            }
        }
        int ans = m * 7;
        for (int i = 0; i < 7; ++i) ans -= MIN(m, abc [i]);
        std::cout << ans << '\n';
    }

    return 0;
}