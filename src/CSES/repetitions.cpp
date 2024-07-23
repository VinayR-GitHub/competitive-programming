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
    int maxlen = 0;
    int cur = s [0];
    int curlen = 1;
    for (int i = 1; i < s.length(); ++i) {
        if (s [i] == cur) {
            ++curlen;
        } else {
            maxlen = MAX(maxlen, curlen);
            curlen = 1;
            cur = s [i];
        }
    }
    maxlen = MAX(maxlen, curlen);
    std::cout << maxlen;
    return 0;
}