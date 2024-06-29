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
    int n, m;
    std::cin >> n >> m;
    long long tot = 0;
    int* c = new int[n * m]{};
    std::vector<int>* cx = new std::vector<int>[100000]{};
    std::vector<int>* cy = new std::vector<int>[100000]{};
    for (int i = 0; i < n * m; ++i) {
        std::cin >> c [i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cx [c [i * m + j] - 1].push_back(i);
            cy [c [i * m + j] - 1].push_back(j);
        }
    }
    for (int i = 0; i < 100000; ++i) {
        std::sort(cx [i].begin(), cx [i].end());
        std::sort(cy [i].begin(), cy [i].end());
        for (int j = 0; j < static_cast<int>(cx [i].size()) - 1; ++j) {
            tot += 1LL * (j + 1) * (cx [i].size() - j - 1) * (cx [i][j + 1] - cx [i][j]);
        }
        for (int j = 0; j < static_cast<int>(cy [i].size()) - 1; ++j) {
            tot += 1LL * (j + 1) * (cy [i].size() - j - 1) * (cy [i][j + 1] - cy [i][j]);
        }
    }
    std::cout << tot;
    return 0;
}