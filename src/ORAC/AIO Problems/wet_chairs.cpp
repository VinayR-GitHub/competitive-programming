#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(chairs);
    int c, n, k; std::cin >> c >> n >> k;
    std::string h2o; std::cin >> h2o;
    int curminlen = INT_MAX;
    int ptr1 = 0, ptr2 = 0;
    int wc = 0, dc = 0;
    for (int i = 0; i < c; ++i) {
        while (true) {
            if (ptr2 == c) break;
            if (h2o [ptr2] == 'w') {
                ++wc;
            } else {
                ++dc;
            }
            if (dc >= (n - k) && (wc + dc) >= n) {
                curminlen = MIN(curminlen, ptr2 - ptr1);
                break;
            } else {
                ++ptr2;
            }
        }
        if (h2o [ptr1] == 'w') {
            --wc;
        } else {
            --dc;
        }
        ++ptr1;
        if (ptr2 == c) break;
        if (h2o [ptr2] == 'w') {
            --wc;
        } else {
            --dc;
        }
    }

    std::cout << (curminlen + 1);

    return 0;
}