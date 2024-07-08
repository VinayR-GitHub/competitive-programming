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
    int t; std::cin >> t;
    while (t--) {
        int n, k; std::cin >> n >> k;
        std::map<int, std::vector<int>> modgroups;
        int ai;
        for (int i = 0; i < n; ++i) {
            std::cin >> ai;
            modgroups [ai % k].push_back(ai / k);
        }
        long long ops = 0LL;
        int numodds = 0;
        for (auto& congclass : modgroups) {
            std::sort(congclass.second.begin(), congclass.second.end());
            int k = congclass.second.size();
            int m = k;
            if (k & 1) {
                ++numodds;
            }
            k >>= 1;
            long long* lefts = new long long[k + 1]{};
            long long* rights = new long long[k + 1]{};
            long long curtot = 0LL;
            for (int i = 0; i < k; ++i) {
                curtot += congclass.second [2 * i + 1];
                curtot -= congclass.second [2 * i];
                lefts [i + 1] = curtot;
            }
            curtot = 0LL;
            for (int i = 0; i < k; ++i) {
                curtot += congclass.second [m - 2 * i - 1];
                curtot -= congclass.second [m - 2 * i - 2];
                rights [i + 1] = curtot;
            }
            long long minops = LLONG_MAX;
            for (int i = 0; i < k + 1; ++i) {
                minops = MIN(minops, lefts [i] + rights [k - i]);
            }
            if (minops == LLONG_MAX) minops = 0;
            ops += minops;
        }
        if (numodds > 1) {
            std::cout << "-1\n";
        } else {
            std::cout << ops << '\n';
        }
    }
    return 0;
}