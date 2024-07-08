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
    int n, m; std::cin >> n >> m;
    int count = 0;
    int tot = 0;
    int hi;
    while (n--) {
        std::cin >> hi;
        tot += hi;
        if (tot <= m) {
            ++count;
        }
    }
    std::cout << count;
    return 0;
}