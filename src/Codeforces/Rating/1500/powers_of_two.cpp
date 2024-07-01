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
    unsigned* a = new unsigned[n]{};
    std::unordered_map<unsigned, unsigned> acounts;
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
        if (acounts.find(a [i]) == acounts.end()) {
            acounts [a [i]] = 1;
        } else {
            ++acounts [a [i]];
        }
    }
    std::unordered_map<unsigned, unsigned> bcounts;
    long long pairs = 0LL;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 32; ++j) {
            unsigned pow2 = 1U << j;
            if (bcounts.find(static_cast<unsigned>(pow2 - a [i])) != bcounts.end()) {
                pairs += 1LL * bcounts [pow2 - a [i]];
            }
        }
        ++bcounts [a [i]];
    }
    std::cout << pairs;
    return 0;
}