#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(nom);
    int n; std::cin >> n;
    if (n == 1) {
        std::cout << 0;
        return 0;
    }
    int* food = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> food [i];

    long long bentor = food [0], jonid = food [1];
    int ptr1 = 0, ptr2 = 1;
    unsigned long long max = 0;
    for (;;) {
        if (jonid == bentor) {
            max = jonid; ++ptr1;
            if (ptr1 == n) break;
            jonid -= food [ptr1];
            bentor += food [ptr1];
        } else if (bentor > jonid) {
            ++ptr2;
            if (ptr2 == n) break;
            jonid += food [ptr2];
        } else if (bentor < jonid) {
            ++ptr1;
            if (ptr1 == n) break;
            jonid -= food [ptr1];
            bentor += food [ptr1];
        }
    }

    std::cout << max;

    return 0;
}