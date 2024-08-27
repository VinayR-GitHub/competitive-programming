#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("tennisin.txt", "r", stdin);
    freopen("tennisout.txt", "w", stdout);
    int n, m;
    std::cin >> n >> m;
    int* a = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
    }
    std::pair<int, int>* b = new std::pair<int, int>[m]{};
    for (int i = 0; i < m; ++i) {
        int aval, bval;
        std::cin >> aval >> bval;
        b [i] = std::make_pair(aval, bval);
    }
    std::vector<std::pair<ll, ll>>* diff = new std::vector<std::pair<ll, ll>>[n]{};
    for (int i = 0; i < n; ++i) {
        diff [i].push_back(std::make_pair(0, 0));
    }
    for (int i = 0; i < m; ++i) {
        if (b [i].first == b [i].second) {
            continue;
        }
        diff [b [i].first - 1].push_back(std::make_pair(diff [b [i].first - 1].back().first - 1, i + 1));
        diff [b [i].second - 1].push_back(std::make_pair(diff [b [i].second - 1].back().first + 1, i + 1));
    }
    ll mintime = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        ll time = 0ll;
        if (diff [i].back().first >= 0) {
            for (auto& dif : diff [i]) {
                if (dif.first + a [i] == -1) {
                    time = dif.second;
                    mintime = std::min(mintime, time);
                    goto NEXT;
                }
            }
        } else {
            ll mindif = 0ll;
            for (auto& dif : diff [i]) {
                mindif = std::min(mindif, dif.first);
            }
            ll val = -1ll * diff [i].back().first;
            ll bignum = (a [i] + mindif + 1ll) / val;
            if ((a [i] + mindif + 1ll) % val != 0) {
                ++bignum;
            }
            a [i] += diff [i].back().first * bignum;
            bignum *= m;
            for (auto& dif : diff [i]) {
                if (dif.first + a [i] == -1) {
                    time = bignum + dif.second;
                    mintime = std::min(mintime, time);
                    goto NEXT;
                }
            }
        }
        NEXT:;
    }
    if (mintime == LLONG_MAX) {
        std::cout << "FOREVER";
    } else {
        std::cout << mintime - 1ll;
    }
    return 0;
}