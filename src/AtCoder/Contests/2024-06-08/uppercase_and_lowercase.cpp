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
    std::string s;
    std::cin >> s;
    int ups = 0;
    int dns = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s [i] <= 'Z') {
            ++ups;
        } else {
            ++dns;
        }
    }
    if (ups > dns) {
        for (int i = 0; i < s.length(); ++i) {
            if (s [i] > 'Z') {
                s [i] -= 32;
            }
        }
    } else {
        for (int i = 0; i < s.length(); ++i) {
            if (s [i] <= 'Z') {
                s [i] += 32;
            }
        }
    }
    std::cout << s;
    return 0;
}