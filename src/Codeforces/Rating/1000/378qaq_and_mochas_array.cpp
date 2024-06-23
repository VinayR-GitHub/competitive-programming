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
        int n; std::cin >> n;
        int* a = new int[n]{};
        for (int i = 0; i < n; ++i) std::cin >> a [i];
        std::sort(a, a + n);
        std::vector<int> divs;
        if (a [0] == 1) {
            std::cout << "yes\n";
            goto NEXT;
        }
        divs.push_back(a [0]);
        for (int i = 0; i < n && divs.size() < 3; ++i) {
            bool div = false;
            for (auto& divisor : divs) {
                if (a [i] % divisor == 0) {
                    div = true;
                    break;
                }
            }
            if (!div) divs.push_back(a [i]);
        }

        if (divs.size() == 3) {
            std::cout << "no\n";
        } else {
            std::cout << "yes\n";
        }

        NEXT:;
    }

    return 0;
}