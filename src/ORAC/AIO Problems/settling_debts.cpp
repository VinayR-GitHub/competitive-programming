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
    FILE(debts);
    int n; std::cin >> n; int csum = 0; int msum = INT_MAX;
    int* money = new int[n]{}; for (int i = 0; i < n; ++i) std::cin >> money [i], csum -= money [i], msum = MIN(msum, csum);

    int the_point_of_no_return = 1;
    if (msum) {
        for (int i = n - 1; i >= 0; --i) {
            msum -= money [i];
            if (msum >= 0) {
                the_point_of_no_return = i + 1;
                break;
            }
        }
    }

    std::cout << the_point_of_no_return;

    return 0;
}