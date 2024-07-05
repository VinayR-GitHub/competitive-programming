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
    int l; std::cin >> l;
    if (l == 1) {
        std::cout << '0';
        return 0;
    }
    int* x = new int[l]{};
    int* y = new int[l]{};
    int* z = new int[l]{};
    for (int i = 0; i < l; ++i) {
        std::cin >> x [i] >> y [i] >> z [i];
    }
    int* scores = new int[l - 1]{};
    for (int i = 0; i < l - 1; ++i) {
        scores [i] = y [i] + y [i + 1] + MAX(x [i] + x [i + 1], z [i] + z [i + 1]);
    }
    short* known = new short[l]{};
    long long* cache = new long long[l]{};
    std::function<long long(int)> solve;
    solve = [&](int loc)->long long {
        if (loc >= l - 1) return 0LL;
        if (known [loc]) return cache [loc];
        known [loc] = 1;
        cache [loc] = MAX(scores [loc] + solve(loc + 2), solve(loc + 1));
        return cache [loc];
    };
    std::cout << solve(0);
    return 0;
}