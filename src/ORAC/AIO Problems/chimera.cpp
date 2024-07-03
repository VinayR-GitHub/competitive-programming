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
    FILE(chim);
    int n; std::cin >> n;
    std::string l, s, g;
    std::cin >> l >> s >> g;
    int num = 0;
    int rands = 0;
    int negls = 0;
    int negss = 0;
    int neggs = 0;
    for (int i = 0; i < n; ++i) {
        if (l [i] == s [i] && s [i] == g [i]) {
            ++num;
        } else if (l [i] == s [i]) {
            ++neggs;
        } else if (l [i] == g [i]) {
            ++negss;
        } else if (s [i] == g [i]) {
            ++negls;
        } else {
            ++rands;
        }
    }
    int lcount = neggs + negss;
    int scount = neggs + negls;
    int gcount = negss + negls;
    while (rands--) {
        if (lcount <= scount && lcount <= gcount) {
            ++lcount;
        } else if (scount <= lcount && scount <= gcount) {
            ++scount;
        } else {
            ++gcount;
        }
    }
    while (true) {
        if (lcount < gcount && lcount < scount && negls) {
            ++lcount;
            --gcount;
            --scount;
            --negls;
        } else if (gcount < lcount && gcount < scount && neggs) {
            ++gcount;
            --lcount;
            --scount;
            --neggs;
        } else if (scount < lcount && scount < gcount && negss) {
            ++scount;
            --lcount;
            --gcount;
            --negss;
        } else break;
    }
    std::cout << num + MIN(lcount, MIN(scount, gcount));
    return 0;
}