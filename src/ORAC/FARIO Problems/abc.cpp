#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int n; std::cin >> n;
    std::set<std::string> dict;
    std::string wi;
    while (n--) {
        std::cin >> wi;
        dict.insert(wi);
    }
    int m; std::cin >> m;
    while (m--) {
        std::cin >> wi;
        if (dict.find(wi) != dict.end()) {
            std::cout << wi << '\n';
            continue;
        }
        for (int i = 0; i < wi.length(); ++i) {
            char cur = wi [i];
            for (char j = 'a'; j < cur; ++j) {
                wi [i] = j;
                if (dict.find(wi) != dict.end()) {
                    std::cout << wi << '\n';
                    goto NEXT;
                }
                wi [i] = cur;
            }
            for (char j = cur + 1; j < '{'; ++j) {
                wi [i] = j;
                if (dict.find(wi) != dict.end()) {
                    std::cout << wi << '\n';
                    goto NEXT;
                }
                wi [i] = cur;
            }
        }
        std::cout << "?\n";
        NEXT:;
    }
    return 0;
}