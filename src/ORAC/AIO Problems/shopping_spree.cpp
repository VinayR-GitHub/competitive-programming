#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("shopin.txt", "r", stdin);
    freopen("shopout.txt", "w", stdout);
    int n, k;
    std::cin >> n >> k;
    int* c = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> c [i];
    }
    ll tot = 0ll;
    for (int i = 0; i < k; ++i) {
        tot += c [i];
    }
    for (int i = k; i < n - k; i += 2) {
        tot += c [i + 1];
    }
    std::cout << tot;
    return 0;
}