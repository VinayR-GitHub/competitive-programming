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
    FILE(art);
    int n; std::cin >> n;
    // PAIR(time, PAIR(width, height))
    std::pair<int, std::pair<int, int>>* data = new std::pair<int, std::pair<int, int>>[n]{};
    int ti, wi, hi;
    for (int i = 0; i < n; ++i) {
        std::cin >> ti >> wi >> hi;
        data [i] = PAIR(ti, PAIR(wi, hi));
    }

    std::deque<std::pair<int, int>> topstack; // PAIR(len, height)
    int max = 0;
    
    topstack.push_front(PAIR(data [0].first + data [0].second.first - 1, data [0].second.second));
    max = topstack.front().second;
    for (int i = 1; i < n; ++i) {
        while (topstack.size()) {
            if (data [i].first > topstack.front().first) {
                topstack.pop_front();
            } else break;
        }
        if (topstack.empty()) {
            topstack.push_front(PAIR(data [i].first + data [i].second.first - 1, data [i].second.second));
        } else {
            topstack.push_front(PAIR(data [i].first + data [i].second.first - 1, data [i].second.second + topstack.front().second));
        }
        max = MAX(max, topstack.front().second);
    }

    std::cout << max;    
    return 0;
}