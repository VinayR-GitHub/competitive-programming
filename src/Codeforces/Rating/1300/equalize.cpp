#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int n; std::cin >> n;
    std::string a, b; std::cin >> a >> b;

    int* c = new int[n]{};
    for (int i = 0; i < n; ++i) {
        c [i] = b [i] - a [i];
    }

    int cost = 0;
    int* fixed = new int[n]{};
    for (int i = 0; i < n - 1; ++i) {
        if (fixed [i]) continue;
        if (c [i] && c [i + 1] && c [i] != c [i + 1]) {
            fixed [i] = 1;
            fixed [i + 1] = 1;
            ++cost;
        } else if (c [i]) {
            ++cost;
        }
    }

    if (!fixed [n - 1] && c [n - 1]) ++cost;

    std::cout << cost;
    return 0;
}