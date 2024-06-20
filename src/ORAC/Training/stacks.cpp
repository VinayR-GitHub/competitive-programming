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

struct Stack {
    std::vector<int> items;

    void pop() {
        items.pop_back();
    }

    void push(int val) {
        items.push_back(val);
    }

    int size() {
        return items.size();
    }

    bool empty() {
        return size() == 0;
    }
};

int main() {
    FILE(stacks);
    Stack contents;
    int input;
    while (true) {
        std::cin >> input;
        if (input == -2) {
            break;
        } else if (input == -1) {
            contents.pop();
        } else {
            contents.push(input);
        }
        if (contents.empty()) {
            std::cout << "stack is empty!\n";
        } else {
            for (auto& item : contents.items) {
                std::cout << item << ' ';
            }
            std::cout << '\n';
        }
    }

    return 0;
}