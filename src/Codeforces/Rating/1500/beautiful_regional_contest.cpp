#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        int pi; std::cin >> pi;
        int prev = pi;
        std::vector<int> nums;
        int cur = 1;
        for (int i = 1; i < n; ++i) {
            std::cin >> pi;
            if (prev == pi) {
                ++cur;
            } else {
                nums.push_back(cur);
                cur = 1;
                prev = pi;
            }
        }
        nums.push_back(cur);
        int g = 0;
        int s = 0;
        int b = 0;
        int iter = 2;
        if (nums.size() < 3) {
            std::cout << "0 0 0\n";
            goto NEXT;
        }
        g = nums [0];
        s = nums [1];
        while (s <= g) {
            if (iter > nums.size() - 1) {
                std::cout << "0 0 0\n";
                goto NEXT;
            }
            s += nums [iter];
            ++iter;
        }
        while (b <= g) {
            if (iter > nums.size() - 1) {
                std::cout << "0 0 0\n";
                goto NEXT;
            }
            b += nums [iter];
            ++iter;
        }
        for (int i = iter; i < nums.size(); ++i) {
            if (2 * (g + s + b + nums [i]) <= n) {
                b += nums [i];
            } else {
                break;
            }
        }
        if (2 * (g + s + b) > n) {
            std::cout << "0 0 0\n";
        } else {
            std::cout << g << ' ';
            std::cout << s << ' ';
            std::cout << b << '\n';
        }
        NEXT:;
    }
    return 0;
}