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
    int* a = new int[n]{};
    for (int i = 0; i < n; ++i) std::cin >> a [i];
    int k; std::cin >> k;
    int* b = new int[k]{};
    for (int i = 0; i < k; ++i) std::cin >> b [i];

    int iter = -1;
    for (int i = 0; i < k; ++i) {
        while (true) {
            ++iter;
            if (a [iter] == b [i]) {
                std::cout << iter + 1 << '\n';
                break;
            }
        }
    }

    return 0;
}