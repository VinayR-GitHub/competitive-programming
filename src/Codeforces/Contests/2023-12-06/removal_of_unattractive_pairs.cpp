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
        std::string s; std::cin >> s;
        int* count = new int[26]{};
        for (int i = 0; i < n; ++i) {
            ++count [s [i] - 'a'];
        }
        std::priority_queue<int> vals;
        for (int i = 0; i < 26; ++i) {
            vals.push(count [i]);
        }
        while (true) {
            int num = vals.top();
            if (!num) break;
            vals.pop();
            int next = vals.top();
            if (!next) break;
            vals.pop();
            --num;
            --next;
            vals.push(num);
            vals.push(next);
            n -= 2;
        }
        std::cout << n << '\n';
    }
    return 0;
}