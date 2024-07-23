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
    int* a = new int[n - 1]{};
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> a [i];
    }
    std::sort(a, a + n - 1);
    for (int i = 1; i < n; ++i) {
        if (a [i - 1] != i) {
            std::cout << i;
            return 0;
        }
    }
    std::cout << n;
    return 0;
}