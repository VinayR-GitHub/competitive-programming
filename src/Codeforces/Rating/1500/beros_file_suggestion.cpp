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
    std::unordered_map<std::string, std::pair<int, std::string>> options;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        int k = s.length();
        std::set<std::string> choices;
        for (int j = 0; j < k; ++j) {
            for (int l = 1; l < k - j + 1; ++l) {
                choices.insert(s.substr(j, l));
            }
        }
        for (auto& str : choices) {
            ++options [str].first;
            if (options [str].second == "") {
                options [str].second = s;
            }
        }
    }
    int q; std::cin >> q;
    while (q--) {
        std::string qstr;
        std::cin >> qstr;
        if (options.find(qstr) == options.end()) {
            std::cout << "0 -\n";
        } else {
            std::cout << options [qstr].first << ' ';
            std::cout << options [qstr].second << '\n';
        }
    }
    return 0;
}