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
    FILE(rad);
    int n, m, k, d; std::cin >> n >> m >> k >> d;
    int* bandwidths = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> bandwidths [i];
    std::vector<int>* adj = new std::vector<int>[n]{}; int ui, vi;
    for (int i = 0; i < m; ++i) std::cin >> ui >> vi, adj [ui - 1].push_back(vi), adj [vi - 1].push_back(ui);
 
    std::deque<int> bfs;
    auto test = [&](int l)->int {
        int* visited = new int[n]{}; int count = 0;
        bfs.push_back(1);
        for (int iter = 0; iter <= d; ++iter) {
            int num = bfs.size(); if (!num) break;
            while (num--) {
                int node = bfs.front(); bfs.pop_front();
                if (visited [node - 1]) continue;
                visited [node - 1] = 1;
                if (bandwidths [node - 1] >= l) {
                    ++count;
                    for (auto& vertex : adj [node - 1]) bfs.push_back(vertex);
                }
            }
        } bool res1 = count >= k;
        bfs.clear();
        if (!res1) return 0;
        count = 0; bfs.push_back(1);
        for (int i = 0; i < n; ++i) visited [i] = 0;
        for (int iter = 0; iter <= d; ++iter) {
            int num = bfs.size(); if (!num) break;
            while (num--) {
                int node = bfs.front(); bfs.pop_front();
                if (visited [node - 1]) continue;
                visited [node - 1] = 1;
                if (bandwidths [node - 1] > l) {
                    ++count;
                    for (auto& vertex : adj [node - 1]) bfs.push_back(vertex);
                }
            }
        } bool res2 = count >= k;
        bfs.clear();
        return 1 + res2;
    };
 
    int low = 0; int high = 1 << 20;
    while (low <= high) {
        int med = (low + high) >> 1;
        switch (test(med)) {
            case 1:
                std::cout << med;
                return 0;
            case 0:
                high = med - 1;
                break;
            case 2:
                low = med + 1;
                break;
        }
    }
 
    std::cout << 0;
 
    return 0;
}