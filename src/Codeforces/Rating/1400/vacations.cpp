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
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
    }
    int* c = new int[4 * n]{};
    int* m = new int[4 * n]{};
    std::function<int(int, bool, bool)> get;
    get = [&](int node, bool dc, bool ds)->int {
        int iter = 4 * node;
        if (dc) ++iter;
        if (ds) iter += 2;
        if (c [iter]) return m [iter];
        if (node == n - 1) {
            c [iter] = 1;
            if (a [n - 1] & 1 && !dc) {
                m [iter] = 0;
                return 0;
            }
            if (a [n - 1] & 2 && !ds) {
                m [iter] = 0;
                return 0;
            }
            m [iter] = 1;
            return 1;
        }
        int val = 1 + get(node + 1, false, false);
        if (a [node] & 1 && !dc) {
            val = MIN(val, get(node + 1, true, false));
        }
        if (a [node] & 2 && !ds) {
            val = MIN(val, get(node + 1, false, true));
        }
        c [iter] = 1;
        m [iter] = val;
        return val;
    };
    std::cout << get(0, false, false);
    return 0;
}