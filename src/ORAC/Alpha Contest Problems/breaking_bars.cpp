#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(NULL);
    int n; std::cin >> n;
    int* cols = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> cols [i];
    int lcount = 0, rcount = 0;
    int* lcults = new int[n]{}; int* rcults = new int[n]{};
    int* lcts = new int[n]{}; int* rcts = new int[n]{};
    
    // Go down from the left.
    for (int i = 0; i < n; ++i) {
        if (!lcults [cols [i] - 1]) {
            lcults [cols [i] - 1] = 1;
            ++lcount;
        }
        lcts [i] = lcount;
    }

    // Go down from the right.
    for (int i = n - 1; i >= 0; --i) {
        if (!rcults [cols [i] - 1]) {
            rcults [cols [i] - 1] = 1;
            ++rcount;
        }
        rcts [i] = rcount;
    }

    int max = INT_MIN;
    for (int i = 0; i < n - 1; ++i) {
        max = MAX(max, lcts [i] + rcts [i + 1]);
    }

    std::cout << max;

    return 0;
}