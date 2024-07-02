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
        int n, k; std::cin >> n >> k;
        k -= 3;
        std::vector<int> choices;
        while (k--) {
            choices.push_back(1);
            --n;
        }
        if (n & 1) {
            choices.push_back(1);
            choices.push_back(n / 2);
            choices.push_back(n / 2);
        } else if (n & 2) {
            choices.push_back(n / 2 - 1);
            choices.push_back(n / 2 - 1);
            choices.push_back(2);
        } else {
            choices.push_back(n / 2);
            choices.push_back(n / 4);
            choices.push_back(n / 4);
        }
        for (auto& item : choices) {
            std::cout << item << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}