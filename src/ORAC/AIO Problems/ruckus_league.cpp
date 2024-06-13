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
    FILE(ruckus);
    int n, l, k, m, li, ri; std::cin >> n >> l >> k >> m;
    std::vector<int>* adj = new std::vector<int>[n]{};
    for (int i = 0; i < l; ++i) {
        std::cin >> li >> ri;
        adj [li - 1].push_back(ri);
        adj [ri - 1].push_back(li);
    }
    int count = 0;

    std::deque<int> bfs;
    std::deque<std::pair<int, int>> forests; // PAIR(line/cycle, num)
    int* visited = new int[n]{};
    for (int i = 0; i < n; ++i) {
        if (visited [i]) continue;
        bfs.push_back(i + 1);
        int num = 0;
        int deg = 0;
        while (bfs.size()) {
            int node = bfs.front(); bfs.pop_front();
            if (visited [node - 1]) continue;
            visited [node - 1] = 1;
            ++num; for (auto& vertex : adj [node - 1]) {
                bfs.push_back(vertex);
            }
            deg += adj [node - 1].size();
        }
        if (num >= m) {
            ++count;
            if (deg == 2 * num) forests.push_back(PAIR(1, 1 - num / m));
            else forests.push_back(PAIR(0, 1 - num / m));
        }
    }

    std::sort(forests.begin(), forests.end());
    while (k > 0 && forests.size()) {
        if (!forests.front().first && forests.front().second < 0) ++count, --k, ++forests.front().second;
        else if (k > 1 && forests.front().second < 0) ++count, k -= 2, ++forests.front().second, forests.front().first = 0;
        else if (forests.front().second >= 0) forests.pop_front();
        else if (k == 1) break;
    }
    std::cout << count;

    return 0;
}