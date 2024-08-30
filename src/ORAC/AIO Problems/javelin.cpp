#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("javelin.txt", "r", stdin);
    freopen("javelout.txt", "w", stdout);
    int n;
    std::cin >> n;
    int curmax = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int d;
        std::cin >> d;
        if (curmax < d) {
            curmax = d;
            ++count;
        }
    }
    std::cout << count;
    return 0;
}