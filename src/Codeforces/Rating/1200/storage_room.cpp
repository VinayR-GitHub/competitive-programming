#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

#define EFFECTIVE_INT_MAX (UINT32_MAX - (1 << 31) - (1 << 30))

int main() {
    ACCEL();
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        int* arr = new int[n * n]{};
        for (int i = 0; i < n * n; ++i) {
            std::cin >> arr [i];
        }

        int* totlocs = new int[n]{};
        for (int i = 0; i < n; ++i) {
            totlocs [i] = EFFECTIVE_INT_MAX;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    totlocs [i] &= arr [i * n + j];
                    totlocs [j] &= arr [i * n + j];
                }
            }
        }

        bool can = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr [i * n + j] != (totlocs [i] | totlocs [j]) && i != j) {
                    can = false;
                    goto END;
                }
            }
        }

        END:;

        if (can) {
            std::cout << "yes\n";
            for (int i = 0; i < n; ++i) {
                std::cout << totlocs [i] << ' ';
            }
            std::cout << '\n';
        } else {
            std::cout << "no\n";
        }
    }

    return 0;
}