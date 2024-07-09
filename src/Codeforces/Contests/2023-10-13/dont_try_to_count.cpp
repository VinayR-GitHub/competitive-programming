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
    int t; std::cin >> t;
    while (t--) {
        int n, m; std::cin >> n >> m;
        std::string x;
        std::string y;
        std::cin >> x >> y;
        int num = 0;
        bool can = false;
        do {
            if (x.find(y) != std::string::npos) {
                can = true;
                break;
            }
            x += x;
            ++num;
        } while (num < 26 && (x.size() <= y.size() * 4 || num < 5));
        if (!can) {
            std::cout << "-1\n";
        } else {
            std::cout << num << '\n';
        }
    }
    return 0;
}