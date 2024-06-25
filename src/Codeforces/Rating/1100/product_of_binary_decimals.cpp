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
    std::vector<int> precompute;
    precompute.push_back(10);
    precompute.push_back(11);
    precompute.push_back(100);
    precompute.push_back(101);
    precompute.push_back(110);
    precompute.push_back(111);
    precompute.push_back(1000);
    precompute.push_back(1001);
    precompute.push_back(1010);
    precompute.push_back(1011);
    precompute.push_back(1100);
    precompute.push_back(1101);
    precompute.push_back(1110);
    precompute.push_back(1111);
    precompute.push_back(10000);
    precompute.push_back(10001);
    precompute.push_back(10010);
    precompute.push_back(10011);
    precompute.push_back(10100);
    precompute.push_back(10101);
    precompute.push_back(10110);
    precompute.push_back(10111);
    precompute.push_back(11000);
    precompute.push_back(11001);
    precompute.push_back(11010);
    precompute.push_back(11011);
    precompute.push_back(11100);
    precompute.push_back(11101);
    precompute.push_back(11110);
    precompute.push_back(11111);
    precompute.push_back(100000);
    int* is_good = new int[100000]{};
    is_good [0] = 1;
    
    std::function<bool(int)> good;
    good = [&](int val)->bool {
        if (is_good [val - 1] == 1) return true;
        if (is_good [val - 1] == -1) return false;
        bool can = false;
        for (auto& factor : precompute) {
            if (val % factor == 0) {
                if (good(val / factor)) {
                    can = true;
                    break;
                }
            }
        }
        if (can) is_good [val - 1] = 1;
        else is_good [val - 1] = -1;
        return can;
    };
    
    while (t--) {
        int n; std::cin >> n;
        bool nice = good(n);
        if (nice) std::cout << "yes\n";
        else std::cout << "no\n";
    }
    
    return 0;
}