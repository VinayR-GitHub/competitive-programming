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
    FILE(leak);
    int n, k; std::cin >> n >> k; int temp;
    std::unordered_map<int, int> cipher;
    for (int i = 0; i < n; ++i) std::cin >> temp, cipher [i + 1] = temp;
    std::set<int> recipe; for (int i = 0; i < k; ++i) std::cin >> temp, recipe.insert(temp);

    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,
                               103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
    std::unordered_map<int, int> primecounts;
    for (auto& prime : primes) primecounts [prime] = 0;

    for (auto& num : recipe) {
        int curchar = num; int iter = 1;
        for (; iter <= n; ++iter) {
            curchar = cipher [curchar];
            if (curchar == num) break;
        }
        if (curchar != num) {
            std::cout << "Never";
            return 0;
        }
        std::unordered_map<int, int> factors;
        for (auto& prime : primes) {
            if (iter % prime == 0) factors [prime] = 0;
            while (iter % prime == 0) {
                ++factors [prime];
                iter /= prime;
            }
            if (iter == 1) break;
        }
        for (auto& pair : factors) primecounts [pair.first] = MAX(primecounts [pair.first], pair.second);
    }

    unsigned long long lcm = 1;
    for (auto& power : primecounts) {
        while (power.second--) lcm *= power.first;
    }

    std::cout << lcm;

    return 0;
}