#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int n, m; std::cin >> n >> m;
    long long bs = n / m;
    long long numgreater = n % m;
    long long numnormal = m - numgreater;
    long long min = 0;
    min += (numnormal * bs * (bs - 1)) >> 1;
    min += (numgreater * bs * (bs + 1)) >> 1;
    long long k = n - m + 1;
    long long max = (k * (k - 1)) >> 1;
    std::cout << min << ' ' << max;
    return 0;
}