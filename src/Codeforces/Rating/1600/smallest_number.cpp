#include <bits/stdc++.h>
 
#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);
 
int main() {
    long long a, b, c, d;
    std::cin >> a >> b >> c >> d;
    char* ops = new char[3]{};
    for (int i = 0; i < 3; ++i) {
        std::cin >> ops [i];
    }
    long long min = LLONG_MAX;
    std::vector<long long> nums;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j) {
                for (int e = 0; e < 3; ++e) {
                    for (int f = 0; f < 3; ++f) {
                        if (e != f) {
                            nums.push_back(a);
                            nums.push_back(b);
                            nums.push_back(c);
                            nums.push_back(d);
                            long long res;
                            if (ops [0] == '+') {
                                res = nums [i] + nums [j];
                            } else {
                                res = nums [i] * nums [j];
                            }
                            nums.erase(nums.begin() + MAX(i, j));
                            nums.erase(nums.begin() + MIN(i, j));
                            nums.push_back(res);
                            if (ops [1] == '+') {
                                res = nums [e] + nums [f];
                            } else {
                                res = nums [e] * nums [f];
                            }
                            nums.erase(nums.begin() + MAX(e, f));
                            nums.erase(nums.begin() + MIN(e, f));
                            nums.push_back(res);
                            if (ops [2] == '+') {
                                min = MIN(min, nums [0] + nums [1]);
                            } else {
                                min = MIN(min, nums [0] * nums [1]);
                            }
                            nums.clear();
                        }
                    }
                }
            }
        }
    }
    std::cout << min;
    return 0;
}