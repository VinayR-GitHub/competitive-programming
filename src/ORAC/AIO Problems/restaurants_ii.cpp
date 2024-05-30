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
    FILE(rest);
    int n, a, b; std::cin >> n >> a >> b; int si, ti;
    std::pair<int, int>* sti = new std::pair<int, int>[n]{};
    std::deque<int> highs, hight;
    long long tot = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> si >> ti;
        sti [i] = PAIR(si, ti);
        if (si >= ti && si > 0) highs.push_back(MIN(si, si - ti)), tot += si;
        else if (ti > si && ti > 0) hight.push_back(MIN(ti, ti - si)), tot += ti;
    }

    if (a < highs.size()) {
        std::sort(highs.begin(), highs.end(), std::less<int>());
        for (int i = a; i < highs.size(); ++i) {
            tot -= highs [i - a];
        }
    }
    if (b < hight.size()) {
        std::sort(hight.begin(), hight.end(), std::less<int>());
        for (int i = b; i < hight.size(); ++i) {
            tot -= hight [i - b];
        }
    }

    std::cout << tot;

    return 0;
}