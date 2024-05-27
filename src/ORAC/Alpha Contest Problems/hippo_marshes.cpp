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
    int n, m; std::cin >> n >> m;
    std::vector<int>* fwadj = new std::vector<int>[n]{}; std::vector<int>* bwadj = new std::vector<int>[n]{};
    int ai, bi; for (int i = 0; i < m; ++i) std::cin >> ai >> bi, fwadj [ai - 1].push_back(bi), bwadj [bi - 1].push_back(ai);

    int* startvisited = new int[n]{}; int* endvisited = new int[n]{};
    std::deque<int> sites; sites.push_back(1);
    while (sites.size()) {
        if (!startvisited [sites.front() - 1]) {
            startvisited [sites.front() - 1] = 1;
            for (auto& next : fwadj [sites.front() - 1]) sites.push_back(next);
        }
        sites.pop_front();
    }
    sites.push_back(n);
    while (sites.size()) {
        if (!endvisited [sites.front() - 1]) {
            endvisited [sites.front() - 1] = 1;
            for (auto& next : bwadj [sites.front() - 1]) sites.push_back(next);
        }
        sites.pop_front();
    }
    
    int count = 0; for (int i = 0; i < n; ++i) if (startvisited [i] && endvisited [i]) ++count;
    std::cout << count;

    return 0;
}