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
    FILE(conv);
    int n, bi; std::cin >> n;

    int* system = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> bi;
        system [bi - 1] = i + 1;
    }

    std::stack<int> order;
    for (int i = n - 1; i > -1; --i) {
        order.push(system [i]);
    }

    std::queue<int> top;
    std::queue<int> bottom;

    for (int i = 0; i < n; ++i) {
        if (i + 1 == order.top()) {
            std::cout << "1\n";
            top.push(i + 1);
        } else {
            std::cout << "2\n";
            bottom.push(i + 1);
        }
        while (true) {
            bool did_something = false;
            if (top.size()) {
                if (top.front() == order.top()) {
                    top.pop();
                    order.pop();
                    did_something = true;
                }
            }
            if (bottom.size()) {
                if (bottom.front() == order.top()) {
                    bottom.pop();
                    order.pop();
                    did_something = true;
                }
            }
            if (!did_something) break;
        }
    }

    return 0;
}