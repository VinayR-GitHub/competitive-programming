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
    int* b = new int[n]{};
    std::pair<int, int>* c = new std::pair<int, int>[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
        std::cin >> b [i];
        c [i] = PAIR(a [i], b [i]);
    }
    std::sort(c, c + n);
    int curtime = c [0].second;
    for (int i = 1; i < n; ++i) {
        if (c [i].second >= curtime) {
            curtime = c [i].second;
        } else {
            curtime = c [i].first;
        }
    }
    std::cout << curtime;
    return 0;
}