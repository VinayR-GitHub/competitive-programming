#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(prime);
    int n; std::cin >> n;
    std::vector<int> primes;
    for (int i = 2; i < n + 1; ++i) {
        for (auto& prime : primes) {
            if (prime > std::sqrt(i)) break;
            if (i % prime == 0) break;
        }
        primes.push_back(i);
    }

    for (auto& prime : primes) {
        std::cout << prime << '\n';
    }

    return 0;
}