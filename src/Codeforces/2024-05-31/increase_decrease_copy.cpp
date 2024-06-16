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
        int* a = new int[n]{};
        int* b = new int[n + 1]{};
        for (int i = 0; i < n; ++i) std::cin >> a [i];
        for (int i = 0; i < n + 1; ++i) std::cin >> b [i];
        long long count = 1;
        int maxdiff = INT_MAX;
        for (int i = 0; i < n; ++i) {
            count += MAG(a [i] - b [i]);
            int curdiff = 0;
            if (b [n] < MIN(a [i], b [i])) curdiff = MIN(a [i], b [i]) - b [n];
            else if (b [n] > MAX(a [i], b [i])) curdiff = b [n] - MAX(a [i], b [i]);
            maxdiff = MIN(maxdiff, curdiff);
        }
        count += maxdiff;
        std::cout << count << '\n';
    }

    return 0;
}