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
        int n, f, k; std::cin >> n >> f >> k;
        int* a = new int[n]{};
        for (int i = 0; i < n; ++i) std::cin >> a [i];
        int fav = a [f - 1];
        std::sort(a, a + n, std::greater<int>());
        if (a [k - 1] > fav) std::cout << "NO\n";
        else if (a [k - 1] < fav) std::cout << "YES\n";
        else {
            if (k == n) {
                std::cout << "YES\n";
            } else if (a [k - 1] == a [k]) std::cout << "MAYBE\n";
            else std::cout << "YES\n";
        }
    }

    return 0;
}