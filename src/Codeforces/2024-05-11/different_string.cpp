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
        std::string str; std::cin >> str;
        int n = str.length();
        int can = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (str [i] != str [i + 1]) can = i;
        }
        if (can == -1) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
            char temp = str [can];
            str [can] = str [can + 1];
            str [can + 1] = temp;
            std::cout << str << '\n';
        }
    }

    return 0;
}