#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int q; std::cin >> q;
    while (q--) {
        long long n; std::cin >> n;
        std::vector<int> ps;
        while (n) {
            if (n % 3 == 0) ps.push_back(0);
            else if (n % 3 == 1) ps.push_back(1);
            else ps.push_back(2);
            n /= 3;
        }
        ps.push_back(0);
        ps.push_back(0);
        while (true) {
            int latest = -1;
            for (int i = 0; i < ps.size(); ++i) {
                if (ps [i] == 2) latest = i;
            }
            if (latest == -1) break;
            for (int i = 0; i < latest + 1; ++i) {
                ps [i] = 0;
            }
            ++ps [latest + 1];
            for (int i = latest + 1; i < ps.size() - 1; ++i) {
                if (ps [i] == 3) {
                    ps [i] = 0;
                    ++ps [i + 1];
                }
            }
        }
        long long m = 0LL;
        long long multiplier = 1;
        for (auto& p : ps) {
            m += multiplier * p;
            multiplier *= 3;
        }
        std::cout << m << '\n';
    }
    return 0;
}