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
    int t; std::cin >> t;
    while (t--) {
        int n, m; std::cin >> n >> m;
        std::string s;
        std::cin >> s;
        int ind;
        std::set<int> inds;
        for (int i = 0; i < m; ++i) {
            std::cin >> ind;
            inds.insert(ind);
        }
        std::string c;
        std::cin >> c;
        std::sort(c.begin(), c.end());
        int k = inds.size();
        for (int i = 0; i < k; ++i) {
            int val = *inds.begin();
            inds.erase(inds.begin());
            s [val - 1] = c [i];
        }
        std::cout << s << '\n';
    }
    return 0;
}