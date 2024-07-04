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
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b [i];
    }
    int* p = new int[n]{};
    int* f = new int[n]{};
    for (int i = 0; i < n; ++i) {
        if (a [i] == b [i]) {
            p [i] = a [i];
            f [a [i] - 1] = 1;
        }
    }
    std::vector<int> m;
    std::vector<int> l;
    for (int i = 0; i < n; ++i) {
        if (!f [i]) {
            l.push_back(i + 1);
        }
        if (!p [i]) {
            m.push_back(i);
        }
    }
    if (m.size() == 1) {
        p [m [0]] = l [0];
    } else {
        if ((a [m [0]] == l [0] || b [m [0]] == l [0]) && (a [m [1]] == l [1] || b [m [1]] == l [1])) {
            p [m [0]] = l [0];
            p [m [1]] = l [1];
        } else {
            p [m [0]] = l [1];
            p [m [1]] = l [0];
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << p [i] << ' ';
    }
    return 0;
}