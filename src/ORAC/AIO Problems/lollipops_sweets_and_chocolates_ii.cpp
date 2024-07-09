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
    FILE(lsc);
    int n, m, l;
    std::cin >> n >> m >> l;
    int* s = new int[n]{};
    int* h = new int[m]{};
    int* t = new int[m]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> s [i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> h [i];
    }
    long long totcount = 0LL;
    for (int i = 0; i < m; ++i) {
        std::cin >> t [i];
        totcount += t [i];
    }
    int low = 0;
    int high = l;
    int res = -1;
    while (low <= high) {
        int mid = low + high >> 1;
        long long thiscount = 0LL;
        for (int i = 0; i < m; ++i) {
            int left = MAX(1, h [i] - mid);
            int right = MIN(l, h [i] + mid);
            int leftindex = std::lower_bound(s, s + n, left) - s;
            int rightindex = std::upper_bound(s, s + n, right) - s - 1;
            thiscount += (rightindex - leftindex + 1);
        }
        if (thiscount == totcount) {
            res = mid;
            break;
        } else if (thiscount < totcount) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (res == -1) {
        std::cout << "-1";
        return 0;
    }
    int* nums = new int[m]{};
    for (int i = 0; i < m; ++i) {
        int left = MAX(1, h [i] - res);
        int right = MIN(l, h [i] + res);
        int leftindex = std::lower_bound(s, s + n, left) - s;
        int rightindex = std::upper_bound(s, s + n, right) - s - 1;
        nums [i] = rightindex - leftindex + 1;
    }
    std::sort(nums, nums + m);
    bool can = true;
    for (int i = 0; i < m; ++i) {
        if (nums [i] != t [i]) {
            can = false;
            break;
        }
    }
    if (can) {
        std::cout << res;
    } else {
        std::cout << "-1";
    }
    return 0;
}