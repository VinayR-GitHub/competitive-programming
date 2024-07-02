#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int n; std::cin >> n;
    int* e = new int[1000000]{};
    int num = 0;
    std::vector<int> days;
    int ai;
    bool can = true;
    int starter = -1;
    std::set<int> has_visited;
    for (int i = 0; i < n; ++i) {
        std::cin >> ai;
        bool in_or_out = ai > 0;
        ai = MAG(ai);
        if (in_or_out && e [ai - 1]) {
            can = false;
            break;
        }
        if (in_or_out && has_visited.find(ai) != has_visited.end()) {
            can = false;
            break;
        }
        if (!in_or_out && !e [ai - 1]) {
            can = false;
            break;
        }
        if (in_or_out) {
            e [ai - 1] = 1;
            ++num;
            has_visited.insert(ai);
        } else {
            e [ai - 1] = 0;
            --num;
            if (num == 0) {
                days.push_back(i - starter);
                starter = i;
                has_visited.clear();
            }
        }
    }
    if (num || !can) {
        std::cout << "-1";
    } else {
        std::cout << days.size() << '\n';
        for (int i = 0; i < days.size(); ++i) {
            std::cout << days [i] << ' ';
        }
    }
    return 0;
}