#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    std::string rsm;
    std::cin >> rsm;
    if (rsm.find('R') < rsm.find('M')) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
    return 0;
}