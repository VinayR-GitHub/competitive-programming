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
    int t; std::cin >> t;
    while (t--) {
        std::string a;
        std::cin >> a;
        std::string b;
        std::cin >> b;
        char temp = a [0];
        a [0] = b [0];
        b [0] = temp;
        std::cout << a << ' ';
        std::cout << b << '\n';
    }
    return 0;
}