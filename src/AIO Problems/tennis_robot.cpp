#include <iostream>
#include <vector>
#include <algorithm>

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
    FILE(tennis);
    int b, n, ptr; std::cin >> b >> n;
    std::vector<std::pair<int, int>> a_; // First is a_i, second is i.
    for (int i = 0; i < b; ++i) std::cin >> ptr, a_.push_back(PAIR(ptr, i + 1));
    std::sort(a_.begin(), a_.end(), std::greater<std::pair<int, int>>());

    int iter = 0; // Indeed, 'tis true.
    // Eliminating invalid options.
    int the_cur; while (true) {
        the_cur = a_.back().first - iter;
        if (the_cur * b < n) {
            n -= (the_cur * b);
            iter = a_.back().first;
            a_.pop_back();
            --b;
        } else {
            break;
        }
    }

    std::sort(a_.begin(), a_.end(), [](auto& f, auto& s) {return (f.second < s.second);});
    // Pinpointing the binlayer.
    int bin; while (true) {
        --the_cur;
        if (the_cur * b < n) {
            n -= (the_cur * b);
            bin = a_ [n - 1].second;
            break;
        }
    }

    std::cout << bin;

    return 0;
}