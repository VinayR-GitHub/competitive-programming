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
    short* adj = new short[676]{};
    short* visited = new short[26]{};
    for (int i = 0; i < 26; ++i) {
        visited [i] = 1;
    }
    while (n--) {
        std::string s;
        std::cin >> s;
        int k = s.length();
        for (int i = 0; i < k; ++i) {
            visited [s [i] - 'a'] = 0;
            for (int j = 0; j < i; ++j) {
                adj [(s [i] - 'a') * 26 + s [j] - 'a'] = 1;
                adj [(s [j] - 'a') * 26 + s [i] - 'a'] = 1;
            }
        }
    }
    int num = 0;
    std::deque<int> bfs;
    for (int i = 0; i < 26; ++i) {
        if (visited [i]) continue;
        bfs.push_back(i);
        while (bfs.size()) {
            int node = bfs.front();
            bfs.pop_front();
            if (visited [node]) continue;
            visited [node] = 1;
            for (int j = 0; j < 26; ++j) {
                if (adj [node * 26 + j]) {
                    bfs.push_back(j);
                }
            }
        }
        ++num;
    }
    std::cout << num;
    return 0;
}