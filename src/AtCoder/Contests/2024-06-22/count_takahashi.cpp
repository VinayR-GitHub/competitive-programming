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
    int tcount = 0;
    std::string si;
    while (n--) {
        std::cin >> si;
        tcount += si [0] == 'T';
    }
    std::cout << tcount;
    return 0;
}