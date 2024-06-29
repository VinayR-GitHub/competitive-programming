#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

struct parabola {
    int a;
    int b;
    int c;
    parabola():
        a (0), b (0), c (0) {};
    parabola(int a, int b, int c):
        a (a), b (b), c (c) {};
    bool disjoint(int otherb) {
        long long discriminant = 1LL * otherb * otherb;
        discriminant -= 4LL * a * c;
        return discriminant < 0LL;
    }
};

int main() {
    ACCEL();
    int t; std::cin >> t;
    while (t--) {
        int n, m; std::cin >> n >> m;
        int* k = new int[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> k [i];
        }
        parabola* abc = new parabola[m]{};
        int ai, bi, ci;
        for (int i = 0; i < m; ++i) {
            std::cin >> ai >> bi >> ci;
            abc [i] = parabola(ai, bi, ci);
        }
        std::sort(k, k + n);
        for (int i = 0; i < m; ++i) {
            int iter = std::lower_bound(k, k + n, abc [i].b) - k;
            if (iter == n) iter = n - 1;
            if (iter) {
                if (abc [i].b - k [iter - 1] < k [iter] - abc [i].b) {
                    --iter;
                }
            }
            if (abc [i].disjoint(k [iter] - abc [i].b)) {
                std::cout << "YES\n";
                std::cout << k [iter] << '\n';
            } else {
                std::cout << "NO\n";
            }
        }
    }
    return 0;
}