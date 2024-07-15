#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int t; std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        std::vector<long long> sequence;
        std::vector<long long> bits;
        for (int i = 0; i < 62; i++) {
            if (n & (1LL << i)) {
                bits.push_back(1LL << i);
            }
        }
        sequence.push_back(n);
        for (auto loc : bits) {
            if (n > loc) {
                sequence.push_back(n - loc);
            }
        }
        std::reverse(sequence.begin(), sequence.end());
        std::cout << sequence.size() << '\n';
        for (auto& el : sequence) {
            std::cout << el << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}