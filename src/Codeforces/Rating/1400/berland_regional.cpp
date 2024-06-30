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
        int n; std::cin >> n;
        std::vector<int>* unis = new std::vector<int>[n]{};
        int ui;
        for (int i = 0; i < n; ++i) {
            std::cin >> ui;
            unis [ui - 1].push_back(i + 1);
        }
        int* s = new int[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> s [i];
        }
        std::vector<long long>* maxskills = new std::vector<long long>[n]{};
        for (int i = 0; i < n; ++i) {
            long long curtot = 0LL;
            for (int j = 0; j < unis [i].size(); ++j) {
                unis [i][j] = s [unis [i][j] - 1];
                curtot += unis [i][j];
            }
            std::sort(unis [i].begin(), unis [i].end());
            for (int j = 0; j < unis [i].size(); ++j) {
                maxskills [i].push_back(curtot);
                curtot -= unis [i][j];
            }
        }
        long long* maxsys = new long long[n]{};
        for (int u = 0; u < n; ++u) {
            for (int i = 1; i < unis [u].size() + 1; ++i) {
                int rem = unis [u].size() % i;
                maxsys [i - 1] += maxskills [u][rem];
            }
        }
        for (int i = 0; i < n; ++i) {
            std::cout << maxsys [i] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}