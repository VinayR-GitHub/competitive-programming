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
    FILE(serv);
    int r, c; std::cin >> r >> c;
    std::pair<int, int> coord = PAIR(1, 1);
    bool ori = true; // up
    while (r * c > 1) {
        char t; std::cin >> t;
        int l; std::cin >> l;
        switch (t) {
            case 'V':
                if (coord.second <= l) {
                    ori = !ori;
                    coord.second = l - coord.second + 1;
                    if (coord.second <= c - l && !ori) {
                        std::cout << "not visible";
                        return 0;
                    }
                } else {
                    coord.second -= l;
                    if (coord.second <= l && ori) {
                        std::cout << "not visible";
                        return 0;
                    }
                }
                c = MAX(l, c - l);
                break;
            case 'v':
                if (coord.second <= l) {
                    ori = !ori;
                    coord.second = l - coord.second + 1;
                    if (coord.second <= c - l && ori) {
                        std::cout << "not visible";
                        return 0;
                    }
                } else {
                    coord.second -= l;
                    if (coord.second <= l && !ori) {
                        std::cout << "not visible";
                        return 0;
                    }
                }
                c = MAX(l, c - l);
                break;
            case 'H':
                if (coord.first <= l) {
                    ori = !ori;
                    coord.first = l - coord.first + 1;
                    if (coord.first <= r - l && !ori) {
                        std::cout << "not visible";
                        return 0;
                    }
                } else {
                    coord.first -= l;
                    if (coord.first <= l && ori) {
                        std::cout << "not visible";
                        return 0;
                    }
                }
                r = MAX(l, r - l);
                break;
            case 'h':
                if (coord.first <= l) {
                    ori = !ori;
                    coord.first = l - coord.first + 1;
                    if (coord.first <= r - l && ori) {
                        std::cout << "not visible";
                        return 0;
                    }
                } else {
                    coord.first -= l;
                    if (coord.first <= l && !ori) {
                        std::cout << "not visible";
                        return 0;
                    }
                }
                r = MAX(l, r - l);
                break;
        }
    }
    std::cout << "visible";
    return 0;
}