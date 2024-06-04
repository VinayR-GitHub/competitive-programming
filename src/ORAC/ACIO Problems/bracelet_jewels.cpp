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
    FILE(jewels);
    int n; std::cin >> n;
    std::string bracelet; std::cin >> bracelet;

    std::vector<int> lumps;
    int curcount = 0;
    char curchar = bracelet [0];
    for (int i = 0; i < n; ++i) {
        if (bracelet [i] == curchar) ++curcount;
        else lumps.push_back(curcount), curcount = 1, curchar = bracelet [i];
    }
    if (lumps.empty()) {
        std::cout << n;
        return 0;
    }
    else if (bracelet [0] == bracelet [n - 1]) lumps [0] += curcount;
    else lumps.push_back(curcount);

    int max = INT_MIN;
    for (int i = 0; i < lumps.size() - 1; ++i) {
        max = MAX(max, lumps [i] + lumps [i + 1]);
    }
    max = MAX(max, lumps [0] + lumps.back());

    std::cout << max;

    return 0;
}