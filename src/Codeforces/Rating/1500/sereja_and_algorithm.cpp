#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    int* xcount = new int[n + 1]{};
    int* ycount = new int[n + 1]{};
    int* zcount = new int[n + 1]{};
    xcount [0] = 0;
    ycount [0] = 0;
    zcount [0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        switch (s [i - 1]) {
            case 'x':
                xcount [i] = xcount [i - 1] + 1;
                ycount [i] = ycount [i - 1];
                zcount [i] = zcount [i - 1];
                break;
            case 'y':
                xcount [i] = xcount [i - 1];
                ycount [i] = ycount [i - 1] + 1;
                zcount [i] = zcount [i - 1];
                break;
            case 'z':
                xcount [i] = xcount [i - 1];
                ycount [i] = ycount [i - 1];
                zcount [i] = zcount [i - 1] + 1;
                break;
        }
    }
    int m; std::cin >> m;
    int li, ri;
    while (m--) {
        std::cin >> li >> ri;
        if (ri - li < 2) {
            std::cout << "YES\n";
            continue;
        }
        int x = xcount [ri] - xcount [li - 1];
        int y = ycount [ri] - ycount [li - 1];
        int z = zcount [ri] - zcount [li - 1];
        int max = MAX(x, MAX(y, z));
        int min = MIN(x, MIN(y, z));
        if (max - min < 2) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}