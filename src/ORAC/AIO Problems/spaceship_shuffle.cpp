#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>

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
    FILE(space);
 
    int n; std::cin >> n;
    auto a_ = new int[n]{}, b_ = new int[n]{};
    auto d_ = new long long[n]{}, e_ = new long long[n]{};
    for (int a = 0; a < n; ++a) std::cin >> a_ [a];
    for (int b = 0; b < n; ++b) std::cin >> b_ [b], d_ [b] = b_ [b] - a_ [b];
 
    long long num = 0;
    for (int i = 0; i < n; ++i) e_ [i] = num, num += d_ [i];
 
    std::sort(e_, e_ + n, std::less<long long>());
 
    long long avg = e_ [(n - 1) >> 1];
    long long cost = 0;
    for (int j = 0; j < n; ++j) cost += MAG(avg - e_ [j]);
 
    std::cout << cost;
 
    return 0;
}