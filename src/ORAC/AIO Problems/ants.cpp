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
    FILE(ants);
    int d; std::cin >> d; --d;
    int cur; std::cin >> cur; int num = 0; bool is_cur_sub = false;
    while (d--) {
        int act; std::cin >> act;
        if (act > cur && !is_cur_sub) {
            is_cur_sub = true;
            ++num;
        }
        if (act <= cur && is_cur_sub) {
            is_cur_sub = false;
        }
        cur = act;
    }

    std::cout << num;

    return 0;
}