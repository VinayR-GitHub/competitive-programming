#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    std::function<long long(int, int)> nCr;
    nCr = [&](int n, int r)->long long {
        long long nfact = 1LL;
        long long nrfact = 1LL;
        for (int i = 1; i < MIN(r + 1, n - r + 1); ++i) {
            nrfact *= i;
        }
        for (int i = MAX(r + 1, n - r + 1); i < n + 1; ++i) {
            nfact *= i;
            long long div = std::gcd(nfact, nrfact);
            nfact /= div;
            nrfact /= div;
        }
        return nfact;
    };
    int n, m, t; std::cin >> n >> m >> t;
    long long options = 0LL;
    for (int i = MAX(4, t - m); i < MIN(n + 1, t); ++i) {
        long long set = 1LL;
        set *= nCr(n, i);
        set *= nCr(m, t - i);
        options += set;
    }
    std::cout << options;
    return 0;
}