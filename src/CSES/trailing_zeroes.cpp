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
    long long n; std::cin >> n;
    int tot = 0;
    long long multip = 5LL;
    while (n) {
        int res = n / multip;
        if (!res) break;
        tot += res;
        multip *= 5LL;
    }
    std::cout << tot;
    return 0;
}