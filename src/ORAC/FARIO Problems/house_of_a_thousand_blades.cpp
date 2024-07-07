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
    int w, h; std::cin >> w >> h;
    int* tops = new int[w]{};
    int* bots = new int[w]{};
    for (int i = 0; i < w; ++i) {
        std::cin >> tops [i];
    }
    for (int i = 0; i < w; ++i) {
        std::cin >> bots [i];
    }
    int num = (tops [0] != h) + (bots [0] != 0);
    for (int i = 0; i < w - 1; ++i) {
        if (tops [i] != tops [i + 1]) {
            ++num;
        }
        if (bots [i] != bots [i + 1]) {
            ++num;
        }
    }
    std::deque<int> stack;
    if (tops [0] != h) {
        stack.push_front(tops [0]);
    }
    for (int i = 1; i < w; ++i) {
        if (tops [i] == h) {
            stack.clear();
            continue;
        }
        while (stack.size()) {
            if (stack.front() < tops [i]) {
                stack.pop_front();
            } else {
                break;
            }
        }
        if (stack.empty()) {
            ++num;
            stack.push_front(tops [i]);
        } else if (stack.front() != tops [i]) {
            ++num;
            stack.push_front(tops [i]);
        }
    }
    stack.clear();
    if (bots [0]) {
        stack.push_front(bots [0]);
    }
    for (int i = 1; i < w; ++i) {
        if (!bots [i]) {
            stack.clear();
            continue;
        }
        while (stack.size()) {
            if (stack.front() > bots [i]) {
                stack.pop_front();
            } else {
                break;
            }
        }
        if (stack.empty()) {
            ++num;
            stack.push_front(bots [i]);
        } else if (stack.front() != bots [i]) {
            ++num;
            stack.push_front(bots [i]);
        }
    }
    std::cout << num;
    return 0;
}