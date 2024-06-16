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
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i + j) % 2 == 0) std::cout << "##";
                else std::cout << "..";
            }
            std::cout << '\n';
            for (int j = 0; j < n; ++j) {
                if ((i + j) % 2 == 0) std::cout << "##";
                else std::cout << "..";
            }
            std::cout << '\n';
        }
    }
    return 0;
}