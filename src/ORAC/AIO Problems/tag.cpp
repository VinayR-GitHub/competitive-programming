#include <iostream>

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
    FILE(tag);
    int n, m, t1, t2; std::cin >> n >> m;
    auto teams = new int[n]{};
    teams [0] = 1; teams [1] = 2;
    int r_ = 1, b_ = 1;
    for (int i = 0; i < m; ++i) std::cin >> t1 >> t2, teams [t2 - 1] = teams [t1 - 1], ++((teams [t2 - 1] == 1) ? r_ : b_);

    std::cout << r_ << " " << b_;

    return 0;
}