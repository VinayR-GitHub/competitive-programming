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
        int* setup = new int[n]{};
        char temp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> temp;
                if (temp == '1') {
                    ++setup [j];
                }
            }
        }
        std::set<int> vals;
        for (int i = 0; i < n; ++i) {
            vals.insert(setup [i]);
        }
        if (vals.size() == 1 || vals.size() == 2 && vals.find(0) != vals.end()) {
            std::cout << "SQUARE\n";
        } else {
            std::cout << "TRIANGLE\n";
        }
    }
    return 0;
}