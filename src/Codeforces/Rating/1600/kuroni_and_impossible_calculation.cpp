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
    int n, m;
    std::cin >> n >> m;
    if (n <= m) {
        int* a = new int[n]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
        }
        long long sum = 1LL;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                sum *= MAG(a [i] - a[j]);
                sum %= m;
            }
        }
        std::cout << sum;
    } else {
        std::cout << '0';
    }
    return 0;
}