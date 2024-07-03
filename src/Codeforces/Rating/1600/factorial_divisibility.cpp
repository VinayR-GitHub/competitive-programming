#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int n, x; std::cin >> n >> x;
    int* acounts = new int[x + 1]{};
    int ai;
    for (int i = 0; i < n; ++i) {
        std::cin >> ai;
        ++acounts [ai];
    }
    int modoffset = 0;
    bool can = true;
    for (int i = 1; i < x; ++i) {
        int set = acounts [i] + modoffset;
        if (set % (i + 1) == 0) {
            modoffset = set / (i + 1);
        } else {
            can = false;
            break;
        }
    }
    if (can) std::cout << "Yes";
    else std::cout << "No";
    return 0;
}