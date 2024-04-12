#include <iostream>
#include <deque>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(farm);
    int n; std::cin >> n;
    int temp; int indeed = 0;
    std::deque<int> plots; for (int i = 0; i < n; ++i) std::cin >> temp, plots.push_back(temp);

    while (plots.size() > 1) {
        if (plots.front() < plots.back()) {
            ++indeed;
            int t = plots.front(); plots.pop_front();
            plots.front() += t;
        } else if (plots.front() > plots.back()) {
            ++indeed;
            int t = plots.back(); plots.pop_back();
            plots.back() += t;
        } else {
            plots.pop_front(); plots.pop_back();
        }
    }

    std::cout << indeed;

    return 0;
}