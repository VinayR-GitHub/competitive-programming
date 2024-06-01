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
    int n; std::cin >> n; int xi, yi;
    std::vector<std::pair<int, std::pair<int, int>>> coords;
    for (int i = 0; i < n; ++i) std::cin >> xi >> yi, coords.push_back(PAIR(i + 1, PAIR(xi, yi)));
    std::vector<int>* verticals = new std::vector<int>[30001]{}; std::vector<int>* horizontals = new std::vector<int>[30001]{};
    std::sort(coords.begin(), coords.end(), [](auto& f, auto& s) {return f.second < s.second;});
    for (int i = 0; i < n; ++i) verticals [coords [i].second.first].push_back(coords [i].first);
    std::sort(coords.begin(), coords.end(), [](auto& f, auto& s) {return f.second.second < s.second.second || s.second.second >= f.second.second && f.second.first < s.second.first;});
    for (int i = 0; i < n; ++i) horizontals [coords [i].second.second].push_back(coords [i].first);

    std::vector<int>* adj = new std::vector<int>[n]{};
    for (int i = 0; i < 30001; ++i) {
        for (int j = 0; j < verticals [i].size(); ++j) {
            if (j) adj [verticals [i][j] - 1].push_back(verticals [i][j - 1]);
            if (j != verticals [i].size() - 1) adj [verticals [i][j] - 1].push_back(verticals [i][j + 1]);
        }
        for (int j = 0; j < horizontals [i].size(); ++j) {
            if (j) adj [horizontals [i][j] - 1].push_back(horizontals [i][j - 1]);
            if (j != horizontals [i].size() - 1) adj [horizontals [i][j] - 1].push_back(horizontals [i][j + 1]);
        }
    }

    std::sort(coords.begin(), coords.end());
    int* visited = new int[n]{};
    int* distances = new int[n]{}; for (int i = 1; i < n; ++i) distances [i] = 1000000000;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> curlocs; curlocs.push(PAIR(0, 1));
    while (curlocs.size()) {
        int node = curlocs.top().second; curlocs.pop();
        if (visited [node - 1]) continue;
        visited [node - 1] = 1;
        for (auto& vertex : adj [node - 1]) {
            distances [vertex - 1] = MIN(distances [vertex - 1], distances [node - 1] + MAG(coords [vertex - 1].second.first + coords [vertex - 1].second.second - coords [node - 1].second.first - coords [node - 1].second.second));
            curlocs.push(PAIR(distances [vertex - 1], vertex));
        }
    }

    std::cout << (distances [n - 1] == 1000000000 ? -1 : distances [n - 1]);

    return 0;
}