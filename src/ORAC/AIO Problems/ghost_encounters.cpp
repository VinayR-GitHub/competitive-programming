#include <iostream>
#include <unordered_map>
#include <algorithm>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(ghost);
    int n, k; std::cin >> n >> k;
    int max = 0;
    std::unordered_map<int, int> spooky_action_at_a_distance;
    for (int i = 0; i < n; ++i) {
        int xi, ti;
        std::cin >> xi >> ti;
        int s_ = ti - (xi * k);
        if (spooky_action_at_a_distance.find(s_) == spooky_action_at_a_distance.end()) {
            spooky_action_at_a_distance [s_] = 1;
        } else {
            ++spooky_action_at_a_distance [s_];
        }
        max = MAX(max, spooky_action_at_a_distance [s_]);
    }

    std::cout << max;

    return 0;
}