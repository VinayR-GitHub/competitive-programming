#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("bookin.txt", "r", stdin);
    freopen("bookout.txt", "w", stdout);
    int n; std::cin >> n;
    std::string s;
    std::cin >> s;
    int loc;
    for (int i = 0; i < n; ++i) {
        if (s [i] == '?') {
            loc = i;
            break;
        }
    }
    if (loc != 0) {
        s [loc] = s [loc - 1];
    } else {
        s [loc] = s [loc + 1];
    }
    int score = 0;
    for (int i = 1; i < n; ++i) {
        score += s [i - 1] == s [i];
    }
    std::cout << score;
    return 0;
}