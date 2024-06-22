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
        int n; std::cin >> n;
        std::string code; std::cin >> code;
        std::set<char> chars;
        for (int i = 0; i < n; ++i) chars.insert(code [i]);
        std::unordered_map<char, char> conv;
        std::set<char>::iterator iters = chars.begin();
        std::set<char>::iterator itere = --chars.end();
        for (int i = 0; i < chars.size(); ++i) {
            conv [*iters] = *itere;
            ++iters;
            --itere;
        }
        for (int i = 0; i < n; ++i) {
            code [i] = conv [code [i]];
        }
        std::cout << code << '\n';
    }

    return 0;
}