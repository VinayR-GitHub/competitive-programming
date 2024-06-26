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
    int n, m; std::cin >> n >> m;
    char* field = new char[n * m]{};
    for (int i = 0; i < n * m; ++i) {
        std::cin >> field [i];
    }

    bool valid = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field [i * m + j] == '*') {
                continue;
            }

            int num = 0;
            if (i) {
                if (j) {
                    if (field [(i - 1) * m + j - 1] == '*') {
                        ++num;
                    }
                }

                if (field [(i - 1) * m + j] == '*') {
                    ++num;
                }

                if (j != m - 1) {
                    if (field [(i - 1) * m + j + 1] == '*') {
                        ++num;
                    }
                }
            }

            if (j) {
                if (field [i * m + j - 1] == '*') {
                    ++num;
                }

                if (i != n - 1) {
                    if (field [(i + 1) * m + j - 1] == '*') {
                        ++num;
                    }
                }
            }

            if (i != n - 1) {
                if (field [(i + 1) * m + j] == '*') {
                    ++num;
                }

                if (j != m - 1) {
                    if (field [(i + 1) * m + j + 1] == '*') {
                        ++num;
                    }
                }
            }

            if (j != m - 1) {
                if (field [i * m + j + 1] == '*') {
                    ++num;
                }
            }

            if (!num) {
                if (field [i * m + j] != '.') {
                    valid = false;
                    goto NEXT;
                }
            } else {
                if (field [i * m + j] != num + 48) {
                    valid = false;
                    goto NEXT;
                }
            }
        }
    }

    NEXT:;

    if (valid) std::cout << "YES\n";
    else std::cout << "NO\n";
    return 0;
}