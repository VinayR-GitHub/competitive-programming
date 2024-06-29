#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int v1, v2, v3, vm;
    std::cin >> v1 >> v2 >> v3 >> vm;
    for (int i = MAX(vm, v1); i < 201; ++i) {
        for (int j = MAX(vm, v2); j < i; ++j) {
            for (int k = MAX(vm, v3); k < j; ++k) {
                if (2 * v1 >= i && 2 * vm < i) {
                    if (2 * v2 >= j && 2 * vm < j) {
                        if (2 * v3 >= k && 2 * vm >= k) {
                            std::cout << i << '\n';
                            std::cout << j << '\n';
                            std::cout << k;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    std::cout << "-1";
    return 0;
}