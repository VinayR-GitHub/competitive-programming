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
        int q; std::cin >> q;
        int ti;
        long long ai, bi, ni;
        long long minhei = 0LL;
        long long maxhei = LLONG_MAX;
        while (q--) {
            std::cin >> ti;
            if (ti == 1) {
                std::cin >> ai >> bi >> ni;
                long long minval = (ni - 2LL) * (ai - bi) + ai + 1LL;
                if (ni == 1) {
                    minval = 0LL;
                }
                long long maxval = (ni - 1LL) * (ai - bi) + ai;
                minval = MAX(minval, minhei);
                maxval = MIN(maxval, maxhei);
                if (maxval < minval) {
                    std::cout << "0 ";
                    continue;
                }
                minhei = minval;
                maxhei = maxval;
                std::cout << "1 ";
            } else {
                std::cin >> ai >> bi;
                long long nmin = (minhei - ai) / (ai - bi);
                nmin += 2LL;
                if ((minhei - ai) % (ai - bi) == 0LL) {
                    --nmin;
                }
                if (minhei <= ai) {
                    nmin = 1LL;
                }
                long long nmax = (maxhei - ai) / (ai - bi);
                nmax += 2LL;
                if ((maxhei - ai) % (ai - bi) == 0LL) {
                    --nmax;
                }
                if (maxhei <= ai) {
                    nmax = 1LL;
                }
                if (nmin == nmax) {
                    std::cout << nmin << ' ';
                } else {
                    std::cout << "-1 ";
                }
            }
        }
        std::cout <<  '\n';
    }
    return 0;
}