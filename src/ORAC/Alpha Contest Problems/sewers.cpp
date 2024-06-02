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
    int r, c, n; std::cin >> r >> c >> n;
    std::string instructions; std::cin >> instructions;
    std::set<int> loci;
    std::pair<int, int> pos = PAIR(0, 0);
    for (int i = 0; i < n; ++i) {
        loci.insert(pos.first * c + pos.second);
        switch (instructions [i]) {
            case 'N':
                --pos.first;
                break;
            case 'E':
                ++pos.second;
                break;
            case 'S':
                ++pos.first;
                break;
            case 'W':
                --pos.second;
                break;
        }
    }
    int end = pos.first * c + pos.second; loci.insert(end);

    std::unordered_map<int, std::vector<int>> adj;
    for (auto& loc : loci) {
        if (loc % c != c - 1 && loci.find(loc + 1) != loci.end()) adj [loc].push_back(loc + 1);
        if (loc % c && loci.find(loc - 1) != loci.end()) adj [loc].push_back(loc - 1);
        if (loc / c != r - 1 && loci.find(loc + c) != loci.end()) adj [loc].push_back(loc + c);
        if (loc / c && loci.find(loc - c) != loci.end()) adj [loc].push_back(loc - c);
    }

    std::deque<std::pair<int, int>> bfs; bfs.push_front(PAIR(0, 0)); // PAIR(loc, prev)
    std::unordered_map<int, int> visited;
    while (bfs.size()) {
        int num = bfs.size();
        while (num--) {
            std::pair<int, int> data = bfs.front(); bfs.pop_front();
            if (visited [data.first]) continue;
            visited [data.first] = data.second + 1;
            for (auto& next : adj [data.first]) {
                bfs.push_back(PAIR(next, data.first));
            }
        }
    }

    std::string journey = "";
    while (end) {
        int prev = visited [end] - 1;
        if (end == prev + 1) journey += 'W';
        else if (end == prev - 1) journey += 'E';
        else if (end == prev + c) journey += 'N';
        else journey += 'S';
        end = prev;
    }

    std::cout << journey.length() << '\n' << journey;

    return 0;
}