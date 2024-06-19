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

struct Queue {
    std::vector<int> items;

    void pop() {
        items.erase(items.begin());
    }

    void push(int item) {
        items.push_back(item);
    }

    int size() {
        return items.size();
    }

    bool empty() {
        return size() == 0;
    }
};

int main() {
    FILE(queues);
    Queue contents;
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
            std::cout << "queue is empty!\n";
        } else {
            for (auto& item : contents.items) {
                std::cout << item << ' ';
            }
            std::cout << '\n';
        }
    }
    
    return 0;
}