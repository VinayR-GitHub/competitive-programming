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
    int* leftc = new int[300001]{};
    int* rghtc = new int[300001]{};
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        int k = s.length();
        int lnum = 0;
        for (int j = 0; j < k; ++j) {
            if (s [j] == '(') {
                ++lnum;
            } else {
                --lnum;
            }
            if (lnum < 0) {
                break;
            }
        }
        if (lnum >= 0) {
            ++leftc [lnum];
        }
        int rnum = 0;
        int rmax = 0;
        for (int j = 0; j < k; ++j) {
            if (s [j] == ')') {
                ++rnum;
            } else {
                --rnum;
            }
            rmax = MAX(rmax, rnum);
        }
        if (rnum == rmax) {
            ++rghtc [rnum];
        }
    }
    long long tot = 0LL;
    for (int i = 0; i < 300001; ++i) {
        tot += 1LL * leftc [i] * rghtc [i];
    }
    std::cout << tot;
    return 0;
}