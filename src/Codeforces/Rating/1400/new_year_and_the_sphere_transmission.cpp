#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    long long n; std::cin >> n;
    std::vector<long long> factors;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (n != i * i) {
                factors.push_back(n / i);
            }
        }
    }
    std::vector<long long> tots;
    for (auto& f : factors) {
        long long res = f - 1;
        res *= n;
        res >>= 1;
        res += f;
        tots.push_back(res);
    }
    std::sort(tots.begin(), tots.end());
    for (auto& val : tots) {
        std::cout << val << ' ';
    }
    return 0;
}