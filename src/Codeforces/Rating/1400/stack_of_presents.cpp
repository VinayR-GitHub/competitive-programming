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
        int* a = new int[n]{};
        std::unordered_map<int, int> backa;
        int* b = new int[m]{};
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
            backa [a [i]] = i;
        }
        for (int i = 0; i < m; ++i) {
            std::cin >> b [i];
        }
        long long changes = 0LL;
        int takenoff = 0;
        int seenlen = -1;
        std::set<int> seen;
        for (int i = 0; i < m; ++i) {
            if (seen.find(b [i]) != seen.end()) {
                ++changes;
                ++takenoff;
                continue;
            }
            int k = backa [b [i]] - takenoff;
            changes += 2 * k + 1;
            for (int j = k + takenoff; j > seenlen; --j) {
                seen.insert(a [j]);
            }
            seenlen = k + takenoff;
            ++takenoff;
        }
        std::cout << changes << '\n';
    }
    return 0;
}