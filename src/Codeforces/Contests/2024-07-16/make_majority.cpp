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
        std::string a;
        std::cin >> a;
        int prev = 1;
        std::vector<int> quick;
        for (int i = 0; i < n; ++i) {
            if (!prev && a [i] == '0') {
                continue;
            }
            quick.push_back(a [i] - '0');
            prev = a [i] - '0';
        }
        int count1 = 0;
        int count2 = 0;
        for (auto& item : quick) {
            if (item) {
                ++count1;
            } else {
                ++count2;
            }
        }
        if (count1 > count2) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    return 0;
}