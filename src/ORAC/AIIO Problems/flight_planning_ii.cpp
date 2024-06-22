#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

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
    ACCEL();
    int n, m; std::cin >> n >> m; int ai, bi, ci;
    int* countries = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> countries [i];

    unsigned long long delta = 0;
    std::vector<std::pair<int, std::pair<int, int>>> cityedges;
    std::vector<std::pair<int, std::pair<int, int>>> countryedges;
    for (int i = 0; i < m; ++i) {
        std::cin >> ai >> bi >> ci;
        if (countries [ai - 1] == countries [bi - 1]) {
            cityedges.push_back(PAIR(ci, PAIR(ai, bi)));
        } else {
            countryedges.push_back(PAIR(ci, PAIR(countries [ai - 1], countries [bi - 1])));
        }
        delta += ci;
    }

    std::sort(cityedges.begin(), cityedges.end());
    std::sort(countryedges.begin(), countryedges.end());

    std::vector<int> cityspan;
    std::vector<int> countryspan;

    disjoint_set<int> pointscit;
    for (int i = 0; i < n; ++i) {
        pointscit.vals [i + 1] = i + 1;
    }

    for (int i = 0; i < cityedges.size(); ++i) {
        int a = pointscit.setfind(cityedges [i].second.first);
        int b = pointscit.setfind(cityedges [i].second.second);
        if (a != b) {
            cityspan.push_back(cityedges [i].first);
            pointscit.setunion(a, b);
        }
    }

    disjoint_set<int> pointsctry;
    for (int i = 0; i < n; ++i) {
        pointsctry.vals [i + 1] = i + 1;
    }

    for (int i = 0; i < countryedges.size(); ++i) {
        int a = pointsctry.setfind(countryedges [i].second.first);
        int b = pointsctry.setfind(countryedges [i].second.second);
        if (a != b) {
            countryspan.push_back(countryedges [i].first);
            pointsctry.setunion(a, b);
        }
    }

    for (auto& len : cityspan) {
        delta -= len;
    }

    for (auto& len : countryspan) {
        delta -= len;
    }

    std::cout << delta;
    return 0;
}