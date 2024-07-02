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
    int n; std::cin >> n;
    int* a = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
    }
    std::vector<std::pair<int, int>> rans;
    std::set<int> seen;
    int starter = 0;
    for (int i = 0; i < n; ++i) {
        if (seen.find(a [i]) == seen.end()) {
            seen.insert(a [i]);
        } else {
            seen.clear();
            rans.push_back(PAIR(starter + 1, i + 1));
            starter = i + 1;
        }
    }
    if (rans.empty()) {
        std::cout << "-1";
    } else {
        rans.back().second = n;
        std::cout << rans.size() << '\n';
        for (auto& ran : rans) {
            std::cout << ran.first << ' ';
            std::cout << ran.second << '\n';
        }
    }
    return 0;
}