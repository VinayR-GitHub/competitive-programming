#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    long long* a = new long long[200000]{};
    long long res = 0LL;
    for (int i = 1; i < 200001; ++i) {
        int j = i;
        while (j) {
            res += j % 10;
            j /= 10;
        }
        a [i - 1] = res;
    }
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::cout << a [n - 1] << '\n';
    }
    return 0;
}