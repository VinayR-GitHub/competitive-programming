#include <iostream>
#include <deque>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(balance);
    int s; std::cin >> s;
    int temp; int indeed = 0;
    std::deque<int> stacks; for (int i = 0; i < s; ++i) std::cin >> temp, stacks.push_back(temp);

    while (stacks.size() > 1) {
        if (stacks.front() < stacks.back()) {
            ++indeed;
            int t = stacks.front(); stacks.pop_front();
            stacks.front() += t;
        } else if (stacks.front() > stacks.back()) {
            ++indeed;
            int t = stacks.back(); stacks.pop_back();
            stacks.back() += t;
        } else {
            stacks.pop_front(); stacks.pop_back();
        }
    }

    std::cout << indeed;

    return 0;
}