#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    long long a, b, x, y;
    std::cin >> a >> b >> x >> y;
    long long candiv = std::gcd(x, y);
    x /= candiv;
    y /= candiv;
    std::pair<long long, long long> dims;
    std::function<int(long long)> check;
    check = [&](long long scale)->int {
        int res = 0;
        long long newx = x * scale;
        long long newy = y * scale;
        if (newx <= a && newy <= b) {
            ++res;
        }
        newx += x;
        newy += y;
        if (newx <= a && newy <= b) {
            ++res;
        }
        return res;
    };
    long long low = 1LL; long long high = 2000000000LL;
    while (low <= high) {
        long long med = low + high >> 1;
        switch (check(med)) {
            case 1:
                dims = PAIR(x * med, y * med);
                low = high + 1;
                break;
            case 0:
                high = med - 1;
                break;
            case 2:
                low = med + 1;
                break;
        }
    }
    std::cout << dims.first << ' ' << dims.second;
    return 0;
}