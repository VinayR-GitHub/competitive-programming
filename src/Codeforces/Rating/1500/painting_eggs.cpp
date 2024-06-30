#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    ACCEL();
    int n; std::cin >> n;
    int* a = new int[n]{};
    int* g = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i];
        std::cin >> g [i];
    }
    long long sa = 0LL;
    long long sg = 0LL;
    std::string res = "";
    for (int i = 0; i < n; ++i) {
        if (MAG(sa - sg + a [i]) <= 500) {
            res += 'A';
            sa += a [i];
        } else {
            res += 'G';
            sg += g [i];
        }
    }
    std::cout << res;
    return 0;
}