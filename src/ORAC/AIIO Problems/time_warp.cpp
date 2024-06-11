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
    int x, w; std::cin >> x >> w;
    int temp; long long tot = 0;
    int* audio = new int[x]{}; for (int i = 0; i < x; ++i) std::cin >> audio [i], tot += audio [i];
    std::set<int> warpers; std::vector<int> warpcounts; for (int i = 0; i < w; ++i) std::cin >> temp, warpers.insert(temp), warpcounts.push_back(temp);

    int num = warpers.size();
    std::unordered_map<int, long long> warp_bonus;
    for (auto& len : warpers) {
        long long curtot = 0;
        for (int i = 0; i < len; ++i) curtot += audio [i];
        long long max = MAX(0LL, curtot);
        for (int i = len; i < x; ++i) {
            curtot += audio [i];
            curtot -= audio [i - len];
            max = MAX(max, curtot);
        }
        warp_bonus [len] = max;
    }

    for (auto& len : warpcounts) tot += warp_bonus [len];

    std::cout << tot;

    return 0;
}