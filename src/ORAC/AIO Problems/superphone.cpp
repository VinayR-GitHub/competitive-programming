#include <iostream>
#include <array>
#include <vector>
#include <climits>
#include <queue>

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
    FILE(phone);
    int n; std::cin >> n;
    int* horizontals = new int[n]{}; int* lefts = new int[n - 1]{}; int* rights = new int[n - 1]{};
    for (int i = 0; i < (n - 1); ++i) {
        std::cin >> lefts [i];
        std::cin >> horizontals [i];
        std::cin >> rights [i];
    } std::cin >> horizontals [n - 1];

    std::vector<std::pair<int, int>>* adj = new std::vector<std::pair<int, int>>[2 * n]{}; // Order from left to right, bottom to top.
    for (int i = 0; i < n; ++i) {
        adj [2 * i].push_back(PAIR((2 * i) + 1, horizontals [i]));
        adj [(2 * i) + 1].push_back(PAIR(2 * i, horizontals [i]));
    }
    for (int i = 0; i < (n - 1); ++i) {
        adj [2 * i].push_back(PAIR((2 * i) + 3, lefts [i]));
        adj [(2 * i) + 1].push_back(PAIR(2 * (i + 1), rights [i]));
    }
    for (int i = 1; i < n; ++i) {
        adj [2 * i].push_back(PAIR((2 * i) - 1, rights [i - 1]));
        adj [(2 * i) + 1].push_back(PAIR(2 * (i - 1), lefts [i - 1]));
    }

    int* visited = new int[2 * n]{};
    int* distances = new int[2 * n]{}; for (int i = 1; i < (2 * n); ++i) distances [i] = INT_MAX;
    std::priority_queue<std::pair<int, int>> curdists; curdists.push(PAIR(0, 0));

    while (curdists.size()) {
        int node = curdists.top().second; curdists.pop();
        if (visited [node]) {
            continue;
        }
        visited [node] = 1;
        for (auto& vertex : adj [node]) {
            if (distances [node] + vertex.second < distances [vertex.first]) {
                distances [vertex.first] = distances [node] + vertex.second;
            }
            curdists.push(PAIR(-distances [vertex.first], vertex.first));
        }
    }

    std::cout << distances [(2 * n) - 1];

    return 0;
}