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

typedef long long ll;

int main() {
    FILE(back);
    int n, k;
    std::cin >> n >> k;
    int* d = new int[n]{};
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> d [i];
    }
    int* c = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> c [i];
    }
    int* nums = new int[20]{}; // excess
    nums [c [0] - 1] = k;
    ll cost = 0ll;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; d [i]; ++j) {
            int adder = MIN(nums [j], d [i]);
            cost += adder * (j + 1);
            nums [j] -= adder;
            d [i] -= adder;
        }
        int betters = 0;
        for (int j = 0; j < c [i + 1] - 1; ++j) {
            betters += nums [j];
        }
        nums [c [i + 1] - 1] = k;
        nums [c [i + 1] - 1] -= betters;
        for (int j = c [i + 1]; j < 20; ++j) {
            nums [j] = 0;
        }
    }
    std::cout << cost;
    return 0;
}