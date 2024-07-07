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
    int n; std::cin >> n;
    long long* p = new long long[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> p [i];
    }
    std::set<int>* adj = new std::set<int>[n]{};
    int ai, bi;
    for (int i = 1; i < n; ++i) {
        std::cin >> ai >> bi;
        adj [ai - 1].insert(bi);
        adj [bi - 1].insert(ai);
    }
    std::set<std::pair<int, std::pair<long long, int>>> order;
    for (int i = 0; i < n; ++i) {
        order.insert(PAIR(adj [i].size(), PAIR(p [i], i + 1)));
    }
    int* curdeg = new int[n]{};
    for (int i = 0; i < n; ++i) {
        curdeg [i] = adj [i].size();
    }
    while (order.size() > 1) {
        std::pair<int, std::pair<long long, int>> node = *order.begin();
        order.erase(order.begin());
        if (node.second.first <= 0) {
            for (auto& vertex : adj [node.second.second - 1]) {
                auto iter = order.find(PAIR(curdeg [vertex - 1], PAIR(p [vertex - 1], vertex)));
                order.erase(iter);
                --curdeg [vertex - 1];
                order.insert(PAIR(curdeg [vertex - 1], PAIR(p [vertex - 1], vertex)));
                auto remove = adj [vertex - 1].find(node.second.second);
                adj [vertex - 1].erase(remove);
            }
        } else {
            for (auto& vertex : adj [node.second.second - 1]) {
                auto iter = order.find(PAIR(curdeg [vertex - 1], PAIR(p [vertex - 1], vertex)));
                order.erase(iter);
                --curdeg [vertex - 1];
                p [vertex - 1] += node.second.first;
                order.insert(PAIR(curdeg [vertex - 1], PAIR(p [vertex - 1], vertex)));
                auto remove = adj [vertex - 1].find(node.second.second);
                adj [vertex - 1].erase(remove);
            }
        }
    }
    std::cout << (*order.begin()).second.first;
    return 0;
}