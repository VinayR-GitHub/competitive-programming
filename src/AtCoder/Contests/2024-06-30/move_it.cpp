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
    int n; std::cin >> n;
    int* a = new int[n]{};
    int* w = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> w [i];
    }
    std::vector<int>* c = new std::vector<int>[n]{};
    for (int i = 0; i < n; ++i) {
        c [a [i] - 1].push_back(w [i]);
    }
    for (int i = 0; i < n; ++i) {
        std::sort(c [i].begin(), c [i].end());
    }
    long long totcost = 0LL;
    for (int i = 0; i < n; ++i) {
        if (c [i].size() > 1) {
            for (int j = 0; j < c [i].size() - 1; ++j) {
                totcost += c [i][j];
            }
        }
    }
    std::cout << totcost;
    return 0;
}