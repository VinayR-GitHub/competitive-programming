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
    FILE(pipes);
    int w, h; std::cin >> w >> h;
    int x, y; std::cin >> x >> y;
    int n; std::cin >> n;
    int* abi = new int[2 * n]{};
    int ai, bi;
    for (int i = 0; i < n; ++i) {
        std::cin >> ai >> bi;
        abi [2 * i] = ai;
        abi [2 * i + 1] = bi;
    }

    std::deque<int> bfs;
    int* dish = new int[w]{};
    int* disv = new int[h]{};
    int val;

    bfs.push_back(0);
    for (int k = 1; bfs.size(); ++k) {
        int num = bfs.size();
        while (num--) {
            int hor = bfs.front();
            bfs.pop_front();
            if (dish [hor]) continue;
            dish [hor] = k;
            for (int i = 0; i < 2 * n; ++i) {
                val = hor + abi [i];
                val %= w;
                bfs.push_back(val);

                val = 500 * w + hor;
                val -= abi [i];
                val %= w;
                bfs.push_back(val);
            }
        }
    }

    bfs.push_back(0);
    for (int k = 1; bfs.size(); ++k) {
        int num = bfs.size();
        while (num--) {
            int hor = bfs.front();
            bfs.pop_front();
            if (disv [hor]) continue;
            disv [hor] = k;
            for (int i = 0; i < 2 * n; ++i) {
                val = hor + abi [i];
                val %= h;
                bfs.push_back(val);

                val = 500 * h + hor;
                val -= abi [i];
                val %= h;
                bfs.push_back(val);
            }
        }
    }

    x %= w;
    y %= h;
    if (!dish [x] && !disv [y]) {
        std::cout << "No\n";
    } else {
        std::cout << MIN(dish [x] ? dish [x] : INT_MAX, disv [y] ? disv [y] : INT_MAX) - 1;
    }

    return 0;
}