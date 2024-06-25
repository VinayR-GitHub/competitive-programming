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
    long long x; std::cin >> x;
    int a;
    long long tot = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        tot += a;
    }

    tot += n;
    --tot;

    if (tot == x) std::cout << "YES\n";
    else std::cout << "NO\n";

    return 0;
}