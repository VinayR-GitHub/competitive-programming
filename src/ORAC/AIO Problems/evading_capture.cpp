#include <iostream>
#include <array>
#include <vector>
#include <set>

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
    FILE(evading);
    int n, e, x, k; std::cin >> n >> e >> x >> k;
    int ai, bi; std::vector<int>* adj = new std::vector<int>[n];
    for (int i = 0; i < e; ++i) std::cin >> ai >> bi, adj [ai - 1].emplace_back(bi), adj [bi - 1].emplace_back(ai);
    int* visited_odds = new int[n]{}; int* visited_evens = new int[n]{};
    int* mindists = new int[n]{};
    std::set<int> curevens = {x}; std::set<int> curodds;
    bool is_even = true;
    int depth = 0;
    int num = 0;
    if (k & 1) {
        // odd
        while (depth < (2 * n + 2)) {
            if (is_even) {
                for (auto& pt : curevens) {
                    if (!visited_evens [pt - 1]) {
                        visited_evens [pt - 1] = 1;
                        for (auto& item : adj [pt - 1]) {
                            curodds.insert(item);
                        }
                    }
                }
                curevens.clear();
            } else {
                for (auto& pt : curodds) {
                    if (!visited_odds [pt - 1]) {
                        visited_odds [pt - 1] = 1;
                        mindists [pt - 1] = depth;
                        for (auto& item : adj [pt - 1]) {
                            curevens.insert(item);
                        }
                    }
                }
                curodds.clear();
            }
            is_even = !is_even;
            ++depth;
        }
    } else {
        // even
        ++num;
        while (depth < (2 * n + 2)) {
            if (is_even) {
                for (auto& pt : curevens) {
                    if (!visited_evens [pt - 1]) {
                        visited_evens [pt - 1] = 1;
                        mindists [pt - 1] = depth;
                        for (auto& item : adj [pt - 1]) {
                            curodds.insert(item);
                        }
                    }
                }
                curevens.clear();
            } else {
                for (auto& pt : curodds) {
                    if (!visited_odds [pt - 1]) {
                        visited_odds [pt - 1] = 1;
                        for (auto& item : adj [pt - 1]) {
                            curevens.insert(item);
                        }
                    }
                }
                curodds.clear();
            }
            is_even = !is_even;
            ++depth;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (mindists [i] && mindists [i] <= k) {
            ++num;
        }
    }

    std::cout << num;

    return 0;
}