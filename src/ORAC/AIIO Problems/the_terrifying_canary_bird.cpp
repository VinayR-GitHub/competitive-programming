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
    FILE(bird);
    int r, c; std::cin >> r >> c;
    int* heights = new int[r * c]{}; for (int i = 0; i < r * c; ++i) std::cin >> heights [i];
    int* possibilities = new int[r * c]{};

    std::vector<std::pair<int, int>> the_lair_of_the_terrifying_canary_bird;
    std::function<int(std::pair<int, int>)> solve;
    solve = [&](std::pair<int, int> node)->int {
        if (possibilities [node.first * c + node.second]) return possibilities [node.first * c + node.second];
        int res = 0;
        bool is_max = true;
        if (node.first) {
            if (heights [(node.first - 1) * c + node.second] < heights [node.first * c + node.second]) res += solve(PAIR(node.first - 1, node.second));
            else is_max = false;
        }
        if (node.second) {
            if (heights [node.first * c + node.second - 1] < heights [node.first * c + node.second]) res += solve(PAIR(node.first, node.second - 1));
            else is_max = false;
        }
        if (node.first != r - 1) {
            if (heights [(node.first + 1) * c + node.second] < heights [node.first * c + node.second]) res += solve(PAIR(node.first + 1, node.second));
            else is_max = false;
        }
        if (node.second != c - 1) {
            if (heights [node.first * c + node.second + 1] < heights [node.first * c + node.second]) res += solve(PAIR(node.first, node.second + 1));
            else is_max = false;
        }
        if (is_max) the_lair_of_the_terrifying_canary_bird.push_back(node);
        if (!res) res = 1;
        possibilities [node.first * c + node.second] = res % 1000003;
        return res % 1000003;
    };

    for (int nodf = 0; nodf < r; ++nodf) for (int nods = 0; nods < c; ++nods) solve(PAIR(nodf, nods));

    unsigned long long tot = 0;
    for (auto& max : the_lair_of_the_terrifying_canary_bird) tot += possibilities [max.first * c + max.second], tot %= 1000003;

    std::cout << tot;

    return 0;
}