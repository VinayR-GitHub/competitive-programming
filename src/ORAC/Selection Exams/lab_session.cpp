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
    FILE(lab);
    int n, p; std::cin >> n >> p;
    int ai, bi;

    std::vector<int>* fwadj = new std::vector<int>[n]{};
    std::vector<int>* bwadj = new std::vector<int>[n]{};
    for (int i = 0; i < p; ++i) {
        std::cin >> ai >> bi;
        fwadj [ai - 1].push_back(bi);
        bwadj [bi - 1].push_back(ai);
    }

    std::vector<int> roots;
    for (int i = 0; i < n; ++i) {
        if (fwadj [i].empty()) {
            roots.push_back(i + 1);
        }
    }

    int* len = new int[n]{};

    std::function<int(int)> find_max;
    find_max = [&](int node)->int {
        if (bwadj [node - 1].empty()) return 1;
        if (len [node - 1]) return len [node - 1];
        int max = 0;
        for (auto& vertex : bwadj [node - 1]) {
            max = MAX(max, find_max(vertex));
        }
        len [node - 1] = max + 1;
        return max + 1;
    };

    int maxlen = 1;
    for (auto& root : roots) {
        maxlen = MAX(maxlen, find_max(root));
        for (int i = 0; i < n; ++i) {
            len [i] = 0;
        }
    }

    std::cout << maxlen;
    return 0;
}