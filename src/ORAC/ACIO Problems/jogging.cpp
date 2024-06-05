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
    int n, m; std::cin >> n >> m; int ui, vi, wi;
    std::vector<std::pair<int, int>>* fwadj = new std::vector<std::pair<int, int>>[n]{}; // PAIR(node, dist)
    std::vector<std::pair<int, int>>* bwadj = new std::vector<std::pair<int, int>>[n]{}; // PAIR(node, dist)
    for (int i = 0; i < m; ++i) std::cin >> ui >> vi >> wi, fwadj [ui - 1].push_back(PAIR(vi, wi)), bwadj [vi - 1].push_back(PAIR(ui, wi));
    
    int* fdists = new int[n]{}; int* bdists = new int[n]{};
    for (int i = 1; i < n; ++i) fdists [i] = 1000000000, bdists [i] = 1000000000;
    int* fv = new int[n]{}; int* bv = new int[n]{};
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> curlocs; curlocs.push(PAIR(0, 1));
    while (curlocs.size()) {
        int node = curlocs.top().second; curlocs.pop();
        if (fv [node - 1]) continue;
        fv [node - 1] = 1;
        for (auto& vertex : fwadj [node - 1]) {
            fdists [vertex.first - 1] = MIN(fdists [vertex.first - 1], fdists [node - 1] + vertex.second);
            curlocs.push(PAIR(fdists [vertex.first - 1], vertex.first));
        }
    }
    curlocs.push(PAIR(0, 1));
    while (curlocs.size()) {
        int node = curlocs.top().second; curlocs.pop();
        if (bv [node - 1]) continue;
        bv [node - 1] = 1;
        for (auto& vertex : bwadj [node - 1]) {
            bdists [vertex.first - 1] = MIN(bdists [vertex.first - 1], bdists [node - 1] + vertex.second);
            curlocs.push(PAIR(bdists [vertex.first - 1], vertex.first));
        }
    }

    for (int i = 1; i < n; ++i) std::cout << ((fdists [i] + bdists [i] >= 1000000000) ? -1 : (fdists [i] + bdists [i])) << '\n';

    return 0;
}