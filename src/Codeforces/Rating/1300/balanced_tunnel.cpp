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
    int ai;
    int* a = new int[n]{};
    int* c = new int[n]{};
    int* b = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> ai;
        a [ai - 1] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> c [i];
    }
    for (int i = 0; i < n; ++i) {
        b [i] = a [c [i] - 1];
    }
    int* mins = new int[n]{};
    int tot = INT_MAX;
    for (int i = n - 1; i > -1; --i) {
        tot = MIN(tot, b [i]);
        mins [i] = tot;
    }
    int count = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (b [i] > mins [i + 1]) ++count;
    }
    std::cout << count;
    return 0;
}