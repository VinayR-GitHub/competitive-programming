#include <iostream>
#include <vector>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;

    while (t--) {
        int k, q; std::cin >> k >> q; int temp;
        std::vector<int> a_ ; for (int i = 0; i < k; ++i) std::cin >> temp, a_.push_back(temp);
        std::vector<int> n_ ; for (int i = 0; i < q; ++i) std::cin >> temp, n_.push_back(temp);
        for (int i = 0; i < q; ++i) {
            std::cout << MIN(a_ [0] - 1, n_ [i]) << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}