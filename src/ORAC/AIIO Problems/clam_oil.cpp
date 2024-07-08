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
    FILE(clam);
    int n, cmax; std::cin >> n >> cmax;
    int* adj = new int[n]{};
    int* p = new int[n]{};
    int* c = new int[n]{};
    int ai;
    std::cin >> p [0] >> c [0];
    for (int i = 1; i < n; ++i) {
        std::cin >> p [i] >> c [i] >> ai;
        adj [i] = ai;
    }
    for (int i = 1; i < n; ++i) {
        p [i] += p [adj [i] - 1];
        c [i] += c [adj [i] - 1];
    }
    short* known = new short[cmax + 1]{};
    long long* maxp = new long long[cmax + 1]{};
    known [0] = 1;
    std::function<long long(int)> solve;
    solve = [&](int allowed)->long long {
        if (known [allowed]) {
            return maxp [allowed];
        }
        long long best = 0LL;
        for (int i = 0; i < n; ++i) {
            if (allowed >= c [i]) {
                best = MAX(best, p [i] + solve(allowed - c [i]));
            }
        }
        known [allowed] = 1;
        maxp [allowed] = best;
        return best;
    };
    std::cout << solve(cmax);
    return 0;
}