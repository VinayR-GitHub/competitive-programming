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
    std::set<int> a;
    int ai;
    while (n--) {
        std::cin >> ai;
        a.insert(ai);
    }
    std::cout << a.size();
    return 0;
}