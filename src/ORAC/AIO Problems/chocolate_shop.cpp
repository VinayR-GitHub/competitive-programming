#include <iostream>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(choc);
    int n; std::cin >> n;
    int temp; int tot = 0;
    for (int i = 0; i < n; ++i) std::cin >> temp, tot += temp;
    tot = 10 - (tot % 10); if (tot == 10) tot = 0;
    std::cout << tot;

    return 0;
}