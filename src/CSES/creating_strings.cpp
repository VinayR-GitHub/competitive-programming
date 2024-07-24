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
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    std::set<std::string> options;
    do {
        options.insert(s);
    } while (std::next_permutation(s.begin(), s.end()));
    std::cout << options.size() << '\n';
    for (auto& val : options) {
        std::cout << val << '\n';
    }
    return 0;
}