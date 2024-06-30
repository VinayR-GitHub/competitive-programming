#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    int* revs = new int[n]{};
    for (int i = 1; i < n; ++i) {
        if (s [i] == 'b') continue;
        if (i && s [i] == 'a') {
            ++revs [i - 1];
            ++revs [i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (revs [i] & 1) {
            std::cout << "1 ";
        } else {
            std::cout << "0 ";
        }
    }
    return 0;
}