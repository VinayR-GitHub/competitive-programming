#include <iostream>
#include <deque>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;
    while (t--) {
        int n; long long k; std::cin >> n >> k; long long temp;
        std::deque<long long> durabs; for (int i = 0; i < n; ++i) std::cin >> temp, durabs.push_back(temp);
        bool turn = true; // LEFT
        while (k > 0LL && durabs.size()) {
            long long val = MIN(durabs.front(), durabs.back()) - 1;
            durabs.front() -= val;
            durabs.back() -= val;
            if (durabs.size() == 1) {
                k -= val;
                --k;
                durabs.pop_front();
                continue;
            }
            if (durabs.front() == 1 && turn) {
                durabs.pop_front();
                k -= (2 * val + 1);
                turn = false;
            } else if (durabs.back() == 1 && !turn) {
                durabs.pop_back();
                k -= (2 * val + 1);
                turn = true;
            } else if (durabs.front() == 1 && !turn) {
                --durabs.back();
                durabs.pop_front();
                k -= (2 * val + 2);
            } else if (durabs.back() == 1 && turn) {
                --durabs.front();
                durabs.pop_back();
                k -= (2 * val + 2);
            }
        }
        if (k < 0LL) {
            --n;
        }

        std::cout << (n - durabs.size()) << '\n';
    }

    return 0;
}