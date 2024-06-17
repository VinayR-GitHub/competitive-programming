#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(snap);
    int n; std::cin >> n;
    int* nums = new int[n + 1]{};
    int lim = 0;
    int count = 0;
    for (int i = 0; i < 2 * n; ++i) {
        int num; std::cin >> num;
        if (i && nums [num - 1] == i) ++count;
        else {
            if (nums [num - 1] > lim) {
                ++count;
                lim = i - 1;
            }
            nums [num - 1] = i + 1;
        }
    }

    std::cout << count;
    return 0;
}