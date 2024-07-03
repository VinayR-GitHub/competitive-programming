#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int n, a, b; std::cin >> n >> a >> b;
    int k = n;
    int numa = 0;
    int numb = -1;
    while (k >= 0) {
        if (k % b == 0) {
            numb = k / b;
            break;
        }
        k -= a;
        ++numa;
    }
    if (numb == -1) {
        std::cout << "-1";
        return 0;
    }
    for (int i = 0; i < numa; ++i) {
        for (int j = 0; j < a - 1; ++j) {
            std::cout << i * a + j + 2 << ' ';
        }
        std::cout << i * a + 1 << ' ';
    }
    for (int i = 0; i < numb; ++i) {
        for (int j = 0; j < b - 1; ++j) {
            std::cout << numa * a + i * b + j + 2 << ' ';
        }
        std::cout << numa * a + i * b + 1 << ' ';
    }
    return 0;
}