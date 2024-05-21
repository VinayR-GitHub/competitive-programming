#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int* depth = new int[2501]{};
std::vector<int>* adj = new std::vector<int>[2501]{};

int set(int i) {
    if (depth [i]) return depth [i];
    int len = 1;
    for (int& next : adj [i]) len = MAX(len, 1 + set(next));
    depth [i] = len;
    return len;
}

int main() {
    FILE(atlan);
    int r, c, a, b; std::cin >> r >> c >> a >> b;
    int* hydro = new int[r * c]{}; for (int i = 0; i < r * c; ++i) std::cin >> hydro [i];

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (i) {
                if (hydro [i * c + j] > hydro [(i - 1) * c + j]) adj [i * c + j].push_back((i - 1) * c + j);
            }
            if (j) {
                if (hydro [i * c + j] > hydro [i * c + j - 1]) adj [i * c + j].push_back(i * c + j - 1);
            }
            if (i != r - 1) {
                if (hydro [i * c + j] > hydro [(i + 1) * c + j]) adj [i * c + j].push_back((i + 1) * c + j);
            }
            if (j != c - 1) {
                if (hydro [i * c + j] > hydro [i * c + j + 1]) adj [i * c + j].push_back(i * c + j + 1);
            }
        }
    }
   
    for (int i = 0; i < r * c; ++i) set(i);
    std::cout << depth [(a - 1) * c + b - 1];

    return 0;
}