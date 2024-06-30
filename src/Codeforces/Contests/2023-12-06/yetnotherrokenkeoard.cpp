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
        std::string s;
        std::cin >> s;
        int n = s.length();
        std::string res = "";
        std::deque<int> bigchars;
        std::deque<int> smlchars;
        int* todelete = new int[n]{};
        for (int i = 0; i < n; ++i) {
            if (s [i] == 'b') {
                todelete [i] = 1;
                if (smlchars.size()) {
                    todelete [smlchars.front()] = 1;
                    smlchars.pop_front();
                }
            } else if (s [i] == 'B') {
                todelete [i] = 1;
                if (bigchars.size()) {
                    todelete [bigchars.front()] = 1;
                    bigchars.pop_front();
                }
            } else if (s [i] >= 'a') {
                smlchars.push_front(i);
            } else {
                bigchars.push_front(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!todelete [i]) std::cout << s [i];
        }
        std::cout << '\n';
    }
    return 0;
}