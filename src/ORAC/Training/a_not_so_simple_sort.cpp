#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(sort);
    int n; std::cin >> n;
    int* m = new int[n]{};
    for (int i = 0; i < n; ++i) std::cin >> m [i];
    std::sort(m, m + n, [](int& f, int& s) {return MAG(f) < MAG(s);});

    for (int i = 0; i < n; ++i) {
        std::cout << m [i] << '\n';
    }
    return 0;
}