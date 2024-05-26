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
    FILE(arth);
    int n; std::cin >> n;
    int p; std::cin >> p;
    std::vector<int>* duels = new std::vector<int>[n]{};
    int tai, tbi; for (int i = 0; i < p; ++i) std::cin >> tai >> tbi, duels [tai - 1].push_back(tbi), duels [tbi - 1].push_back(tai);
    int* visited = new int[n]{};
    std::deque<int> loci;
    std::vector<std::pair<int, int>> sets;
    for (int i = 0; i < n; ++i) {
        if (!visited [i]) {
            visited [i] = 1;
            loci.push_back(i + 1);
            sets.push_back(PAIR(0, 0));
            ++sets.back().first;
            int count = 0;
            while (loci.size()) {
                int num = loci.size();
                for (int j = 0; j < num; ++j) {
                    for (auto& nexts : duels [loci.front() - 1]) {
                        if (!visited [nexts - 1]) {
                            visited [nexts - 1] = 1;
                            loci.push_back(nexts);
                            if (count & 1) ++sets.back().first;
                            else ++sets.back().second;
                        }
                    }
                    loci.pop_front();
                }
                ++count;
            }
        }
    }

    int total = 0;
    for (auto& option : sets) {
        total += MAX(option.first, option.second);
    }

    std::cout << total;

    return 0;
}