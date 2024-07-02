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
    FILE(taxi);
    int s, n; std::cin >> s >> n;
    std::vector<std::pair<int, int>> tt;
    int ci, si;
    for (int i = 0; i < n; ++i) {
        std::cin >> ci >> si;
        tt.push_back(PAIR(ci, si));
    }

    long long* known = new long long[s + 1]{};
    long long* cache = new long long[s + 1]{};
    known [0] = 1;
    cache [0] = 0;
    std::function<long long(int)> mincost;
    mincost = [&](int people)->long long {
        if (known [people]) {
            return cache [people];
        }
        long long cost = INT_MAX;
        for (auto& taxi : tt) {
            if (people >= taxi.second - 1) {
                long long op1 = mincost(MAX(0, people - taxi.second));
                long long op2 = INT_MAX;
                if (taxi.second != 1) {
                    op2 = mincost(MAX(0, people - taxi.second + 1));
                }
                cost = MIN(cost, MIN(op1, op2) + taxi.first);
            }
        }
        known [people] = 1;
        cache [people] = cost;
        return cost;
    };

    std::cout << mincost(s);
    return 0;
}