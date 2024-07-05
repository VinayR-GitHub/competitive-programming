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
    FILE(jugs);
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::pair<short, int>* visited = new std::pair<short, int>[1002001]{};
    std::deque<std::pair<int, int>> cachebfs;
    cachebfs.push_back(PAIR(1001 * a, -1));
    int endpoint = -1;
    while (cachebfs.size()) {
        int val = cachebfs.front().first;
        int old = cachebfs.front().second;
        cachebfs.pop_front();
        if (visited [val].first) {
            continue;
        }
        int x = val / 1001;
        int y = val % 1001;
        int z = a - x - y;
        visited [val] = PAIR(1, old);
        int xi, yi, zi;
        if (x == d || y == d || z == d) {
            endpoint = val;
            goto CHECKED;
        }
        // A->B
        yi = MIN(b, y + x);
        xi = x + y - yi;
        if (!visited [1001 * xi + yi].first) {
            cachebfs.push_back(PAIR(1001 * xi + yi, val));
        }
        // A->C
        zi = MIN(c, z + x);
        xi = x + z - zi;
        yi = a - xi - zi;
        if (!visited [1001 * xi + yi].first) {
            cachebfs.push_back(PAIR(1001 * xi + yi, val));
        }
        // B->A
        xi = MIN(a, x + y);
        yi = y + x - xi;
        if (!visited [1001 * xi + yi].first) {
            cachebfs.push_back(PAIR(1001 * xi + yi, val));
        }
        // B->C
        zi = MIN(c, z + y);
        yi = y + z - zi;
        xi = a - yi - zi;
        if (!visited [1001 * xi + yi].first) {
            cachebfs.push_back(PAIR(1001 * xi + yi, val));
        }
        // C->A
        xi = MIN(a, x + z);
        zi = z + x - xi;
        yi = a - xi - zi;
        if (!visited [1001 * xi + yi].first) {
            cachebfs.push_back(PAIR(1001 * xi + yi, val));
        }
        // C->B
        yi = MIN(b, y + z);
        zi = z + y - yi;
        xi = a - yi - zi;
        if (!visited [1001 * xi + yi].first) {
            cachebfs.push_back(PAIR(1001 * xi + yi, val));
        }
    }
    CHECKED:;
    if (endpoint == -1) {
        std::cout << "0 0";
        return 0;
    }
    std::deque<int> process;
    process.push_back(endpoint);
    while (true) {
        int node = process.front();
        if (node == -1) {
            break;
        }
        process.push_front(visited [node].second);
    }
    process.pop_front();
    while (process.size() > 1) {
        int val1 = process.front();
        process.pop_front();
        int val2 = process.front();
        int x1 = val1 / 1001;
        int y1 = val1 % 1001;
        int z1 = a - x1 - y1;
        int x2 = val2 / 1001;
        int y2 = val2 % 1001;
        int z2 = a - x2 - y2;
        if (x1 == x2) {
            if (y1 > y2) {
                std::cout << "2 3\n";
            } else {
                std::cout << "3 2\n";
            }
        } else if (y1 == y2) {
            if (x1 > x2) {
                std::cout << "1 3\n";
            } else {
                std::cout << "3 1\n";
            }
        } else {
            if (x1 > x2) {
                std::cout << "1 2\n";
            } else {
                std::cout << "2 1\n";
            }
        }
    }
    int nx = process.front() / 1001;
    int ny = process.front() % 1001;
    int nz = a - nx - ny;
    if (nx == d) {
        std::cout << "0 1";
    } else if (ny == d) {
        std::cout << "0 2";
    } else {
        std::cout << "0 3";
    }
    return 0;
}