#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int a, b, n, k; std::cin >> a >> b >> n;
    int c = a;
    std::vector<char> additions;
    for (int i = 0; i < n; ++i) {
        c *= 10;
        c %= b;
        k = b - c;
        if (k == b) k = 0;
        if (k > 9) break;
        additions.push_back(k + 48);
        c = 0;
    }
    if (additions.size() != n) {
        std::cout << "-1";
    } else {
        std::cout << a;
        for (int i = 0; i < n; ++i) {
            std::cout << additions [i];
        }
    }
    return 0;
}