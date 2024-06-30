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
    int* m = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> m [i];
    }
    int* s = new int[n]{};
    long long max = 0LL;
    for (int i = 0; i < n; ++i) {
        int* o = new int[n]{};
        o [i] = m [i];
        long long tot = m [i];
        int curmin = m [i];
        for (int j = i - 1; j >= 0; --j) {
            o [j] = MIN(m [j], curmin);
            curmin = MIN(curmin, m [j]);
            tot += o [j];
        }
        curmin = m [i];
        for (int j = i + 1; j < n; ++j) {
            o [j] = MIN(m [j], curmin);
            curmin = MIN(curmin, m [j]);
            tot += o [j];
        }
        if (tot > max) {
            for (int j = 0; j < n; ++j) {
                s [j] = o [j];
            }
        }
        max = MAX(max, tot);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << s [i] << ' ';
    }
    return 0;
}