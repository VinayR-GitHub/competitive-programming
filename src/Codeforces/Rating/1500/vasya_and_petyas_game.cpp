#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int n; std::cin >> n;
    std::vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        for (auto& prime : primes) {
            if (prime > std::sqrt(i)) break;
            if (i % prime == 0) goto NEXT;
        }
        primes.push_back(i);
        NEXT:;
    }
    std::vector<int> primepowers;
    for (auto& prime : primes) {
        int val = prime;
        while (val <= n) {
            primepowers.push_back(val);
            val *= prime;
        }
    }
    std::cout << primepowers.size() << '\n';
    for (auto& pp : primepowers) {
        std::cout << pp << ' ';
    }
    return 0;
}