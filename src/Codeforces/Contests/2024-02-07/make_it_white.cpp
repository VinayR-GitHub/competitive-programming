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
        std::string s;
        std::cin >> s;
        std::deque<int> blacks;
        for (int i = 0; i < n; ++i) {
            if (s [i] == 'B') {
                blacks.push_back(i);
            }
        }
        if (blacks.empty()) {
            std::cout << "0\n";
        } else {
            std::cout << blacks.back() - blacks.front() + 1 << '\n';
        }
    }
    return 0;
}