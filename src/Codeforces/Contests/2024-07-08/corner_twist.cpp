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
    int t; std::cin >> t;
    while (t--) {
        int n, m; std::cin >> n >> m;
        int* a = new int[n * m]{};
        int* b = new int[n * m]{};
        char temp;
        for (int i = 0; i < n * m; ++i) {
            std::cin >> temp;
            a [i] = temp - '0';
        }
        for (int i = 0; i < n * m; ++i) {
            std::cin >> temp;
            b [i] = temp - '0';
        }
        for (int i = 0; i < n; ++i) {
            int asum = 3;
            int bsum = 3;
            for (int j = 0; j < m; ++j) {
                asum += a [i * m + j];
                bsum += b [i * m + j];
            }
            asum %= 3;
            bsum %= 3;
            if (asum - bsum != 0) {
                std::cout << "No\n";
                goto NEXT;
            }
        }
        for (int i = 0; i < m; ++i) {
            int asum = 3;
            int bsum = 3;
            for (int j = 0; j < n; ++j) {
                asum += a [j * m + i];
                bsum += b [j * m + i];
            }
            asum %= 3;
            bsum %= 3;
            if (asum - bsum != 0) {
                std::cout << "No\n";
                goto NEXT;
            }
        }
        std::cout << "Yes\n";
        NEXT:;
    }
    return 0;
}