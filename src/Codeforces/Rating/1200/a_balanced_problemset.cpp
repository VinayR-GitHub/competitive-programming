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
    int t; std::cin >> t;
    while (t--) {
        int x, n; std::cin >> x >> n;

        std::deque<int> factors;
        std::deque<int> factorsupper;
        for (int i = 1; i < std::round(std::sqrt(x)) + 1; ++i) {
            if (x % i == 0) {
                factors.push_back(i);
                factorsupper.push_front(x / i);
            }
        }

        if (factors.back() == factorsupper.front()) {
            factorsupper.pop_front();
        }

        while (factorsupper.size()) {
            factors.push_back(factorsupper.front());
            factorsupper.pop_front();
        }

        int max;
        for (int i = 0; i < factors.size(); ++i) {
            if (factors [i] >= n) {
                max = factors [i];
                break;
            }
        }

        std::cout << x / max << '\n';
    }

    return 0;
}