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
    int n; std::cin >> n; int temp;
    int cur = 0;
    long long sweat = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        sweat += MAX(0, temp - cur);
        cur = temp;
    }

    std::cout << sweat;
    return 0;
}