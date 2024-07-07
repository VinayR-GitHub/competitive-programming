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

template<class T> class disjoint_set {
public:
    std::unordered_map<T, T> vals;

    T setfind(T loc) {
        T next = vals.count(loc) ? vals [loc] : loc;
        if (next != loc) {
            next = setfind(next);
            vals [loc] = next;
        }
        return next;
    }

    void setunion(T vala, T valb) {
        vals [setfind(vala)] = setfind(valb);
    }
};

int main() {
    FILE(train);
    int n; std::cin >> n;
    std::pair<std::pair<int, int>, std::pair<int, int>>* tracks = new std::pair<std::pair<int, int>, std::pair<int, int>>[n]{};
    int x1, y1, x2, y2;
    for (int i = 0; i < n; ++i) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        tracks [i] = PAIR(PAIR(x1, y1), PAIR(x2, y2));
    }
    long long tot = 0LL;
    std::vector<std::pair<int, std::pair<int, int>>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (tracks [i].first.first == tracks [i].second.first) {
                if (tracks [j].first.first == tracks [j].second.first) {
                    goto NEXT;
                }
                if (tracks [j].first.second >= MIN(tracks [i].first.second, tracks [i].second.second)) {
                    if (tracks [j].first.second <= MAX(tracks [i].first.second, tracks [i].second.second)) {
                        if (tracks [i].first.first >= MIN(tracks [j].first.first, tracks [j].second.first)) {
                            if (tracks [i].first.first <= MAX(tracks [j].first.first, tracks [j].second.first)) {
                                edges.push_back(PAIR(MAG(tracks [i].first.first) + MAG(tracks [j].first.second), PAIR(i + 1, j + 1)));
                                tot += edges.back().first;
                            }
                        }
                    }
                }
            }
            if (tracks [i].first.second == tracks [i].second.second) {
                if (tracks [j].first.second == tracks [j].second.second) {
                    goto NEXT;
                }
                if (tracks [i].first.second >= MIN(tracks [j].first.second, tracks [j].second.second)) {
                    if (tracks [i].first.second <= MAX(tracks [j].first.second, tracks [j].second.second)) {
                        if (tracks [j].first.first >= MIN(tracks [i].first.first, tracks [i].second.first)) {
                            if (tracks [j].first.first <= MAX(tracks [i].first.first, tracks [i].second.first)) {
                                edges.push_back(PAIR(MAG(tracks [i].first.second) + MAG(tracks [j].first.first), PAIR(i + 1, j + 1)));
                                tot += edges.back().first;
                            }
                        }
                    }
                }
            }
            NEXT:;
        }
    }

    std::sort(edges.begin(), edges.end());
    std::vector<int> span;
    disjoint_set<int> network;
    for (int i = 0; i < n; ++i) {
        network.vals [i + 1] = i + 1;
    }
    for (int i = 0; i < edges.size(); ++i) {
        int a = network.setfind(edges [i].second.first);
        int b = network.setfind(edges [i].second.second);
        if (a != b) {
            span.push_back(edges [i].first);
            if (span.size() == n - 1) {
                break;
            }
            network.setunion(a, b);
        }
    }
    for (auto& len : span) {
        tot -= len;
    }
    std::cout << tot;
    return 0;
}