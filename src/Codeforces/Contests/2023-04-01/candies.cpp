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
        std::vector<int> option;
        if (n % 2 == 0) {
            std::cout << "-1\n";
            continue;
        }
        while (n != 1) {
            if (n % 4 == 1) {
                option.push_back(1);
                ++n;
                n >>= 1;
            } else if (n % 4 == 3) {
                option.push_back(2);
                --n;
                n >>= 1;
            }
        }
        std::reverse(option.begin(), option.end());
        std::cout << option.size() << '\n';
        for (auto& pick : option) {
            std::cout << pick << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}