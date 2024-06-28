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
    std::string s; std::cin >> s;
    bool cur = true;
    int iter = 1;
    for (int i = 0; i < s.length(); ++i) {
        if (s [i] == '0') {
            std::cout << "3 " << iter << '\n';
            ++iter;
            if (iter == 5) iter = 1;
        } else {
            std::cout << "1 " << (cur ? 1 : 3) << '\n';
            cur = !cur;
        }
    }
    return 0;
}