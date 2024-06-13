#include <bits/stdc++.h>
 
#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)
 
int main() {
    FILE(space);
    int w, h, k, pi; std::cin >> w >> h >> k;
    std::vector<std::pair<int, int>> motherships;
    for (int i = 0; i < k; ++i) {
        int minran = INT_MAX, maxran = INT_MIN;
        std::cin >> pi; int temp, arb;
        while (pi--) {
            std::cin >> temp >> arb;
            minran = MIN(minran, temp);
            maxran = MAX(maxran, temp);
        }
        if (minran != maxran) motherships.push_back(PAIR(minran + 1, maxran));
    }
 
    std::sort(motherships.begin(), motherships.end());
    std::vector<std::pair<int, int>> disjoints;
    if (motherships.empty()) {
        std::cout << w;
        return 0;
    }
    disjoints.push_back(motherships [0]);
    for (int i = 1; i < motherships.size(); ++i) {
        if (motherships [i].first <= disjoints.back().second) {
            disjoints.back().second = MAX(disjoints.back().second, motherships [i].second);
        } else {
            disjoints.push_back(motherships [i]);
        }
    }
 
    for (auto& pair : disjoints) {
        w -= (pair.second - pair.first + 1);
    }
 
    std::cout << w;
    return 0;
}