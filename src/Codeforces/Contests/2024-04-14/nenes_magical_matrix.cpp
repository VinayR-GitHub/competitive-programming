#include <iostream>
#include <string>
#include <cmath>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;

    while (t--) {
        int n; std::cin >> n;
        int s, m;
        m = 2 * n;
        s = n * (n + 1) * ((4 * n) - 1) / 6;
        std::cout << s << ' ' << m << '\n';
        std::string num_lit;
        for (int i = 0; i < n; ++i) num_lit += std::to_string(i + 1), num_lit += ' '; num_lit.pop_back();
        for (int i = 0; i < n; ++i) std::cout << "1 " << (n - i) << ' ' << num_lit << '\n' << "2 " << (n - i) << ' ' << num_lit << '\n';
    }

    return 0;
}