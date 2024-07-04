#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    std::string s, t;
    std::cin >> s >> t;
    int n = s.length();
    int k = t.length();
    for (int c = 1; c < n; ++c) {
        for (int j = 0; j < c; ++j) {
            std::string res = "";
            for (int i = 0; i < n; ++i) {
                int iter = i * c + j;
                if (iter >= n) break;
                res += s [iter];
            }
            if (t == res) {
                std::cout << "Yes";
                return 0;
            }
        }
    }
    std::cout << "No";
    return 0;
}