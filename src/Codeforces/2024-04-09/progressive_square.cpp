#include <iostream>
#include <set>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;
    while (t--) {
        int n, c, d; std::cin >> n >> c >> d;
        std::multiset<int> items; int temp;
        for (int i = 0; i < (n * n); ++i) std::cin >> temp, items.insert(temp);
        int a_ = *items.begin();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                auto iter = items.find(a_ + (i * c) + (j * d));
                if (iter == items.end()) goto NO;
                items.erase(iter);
            }
        }
        std::cout << "YES\n";
        continue;

        NO:
            std::cout << "NO\n";
    }

    return 0;
}