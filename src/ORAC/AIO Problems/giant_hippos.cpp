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
    FILE(hippo);
    int n, h, f; std::cin >> n >> h >> f; int temp;
    int* eating = new int[n]{}; for (int i = 0; i < h; ++i) std::cin >> temp, eating [temp - 1] = 1;
    std::vector<int> lengths; int curmax = 0; for (int i = 0; i < n; ++i) {
        if (!eating [i]) ++curmax;
        else lengths.push_back(curmax), curmax = 0;
    }
    lengths.push_back(curmax);
    
    int min = lengths [0];
    int max = lengths [h];
    
    lengths.erase(lengths.begin()); lengths.pop_back();
    std::sort(lengths.begin(), lengths.end(), std::greater<int>());
    int case1 = 0;
    for (int i = 0; i < MIN(f / 2, h - 1); ++i) case1 += lengths [i];

    int case2 = min + max;
    for (int i = 0; i < MIN(f / 2 - 1, h - 1); ++i) case2 += lengths [i];

    int case3 = MAX(min, max);
    for (int i = 0; i < MIN((f - 1) / 2, h - 1); ++i) case3 += lengths [i];

    if (f != 1) std::cout << MAX(case1, MAX(case2, case3));
    else std::cout << MAX(case1, case3);

    return 0;
}