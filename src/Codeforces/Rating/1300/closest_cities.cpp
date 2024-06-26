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
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
        }

        int m; std::cin >> m;
        std::pair<int, int>* q = new std::pair<int, int>[m]{};
        int xi, yi;
        for (int i = 0; i < m; ++i) {
            std::cin >> xi >> yi;
            q [i] = PAIR(xi, yi);
        }

        int* totdistsl = new int[n]{};
        int* totdistsr = new int[n]{};

        int tot = 0;
        for (int i = 0; i < n - 1; ++i) {
            int op1 = INT_MAX;
            int op2 = INT_MAX;
            if (i) {
                op1 = a [i] - a [i - 1];
            }
            op2 = a [i + 1] - a [i];

            if (op2 < op1) ++tot;
            else {
                tot -= a [i];
                tot += a [i + 1];
            }

            totdistsl [i + 1] = tot;
        }

        tot = 0;
        for (int i = n - 1; i > 0; --i) {
            int op1 = INT_MAX;
            int op2 = INT_MAX;
            if (i != n - 1) {
                op1 = a [i + 1] - a [i];
            }
            op2 = a [i] - a [i - 1];

            if (op2 < op1) ++tot;
            else {
                tot -= a [i - 1];
                tot += a [i];
            }

            totdistsr [i - 1] = tot;
        }

        for (int i = 0; i < m; ++i) {
            if (q [i].first < q [i].second) {
                std::cout << totdistsl [q [i].second - 1] - totdistsl [q [i].first - 1] << '\n';
            } else {
                std::cout << totdistsr [q [i].second - 1] - totdistsr [q [i].first - 1] << '\n';
            }
        }
    }

    return 0;
}