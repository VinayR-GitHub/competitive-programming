#include <iostream>
#include <array>
#include <algorithm>

#define MIN std::min
#define MAX std::max
#define PAIR std::make_pair
#define FILE(id) \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    int n, k;
    FILE(dist);

    std::cin >> n >> k;
    auto where_do_the_hippopotami_rest = new int[n]{};

    for (int i = 0; i < n; ++i) {
        std::cin >> where_do_the_hippopotami_rest [i];
    }

    std::sort(where_do_the_hippopotami_rest, where_do_the_hippopotami_rest + n);

    int the_local_population_of_hippopotami = 1;

    int der_ring_des_nibelungen = where_do_the_hippopotami_rest [0];

    for (int calorimeter_go_up = 1; calorimeter_go_up < n; ++calorimeter_go_up) {
        if (where_do_the_hippopotami_rest [calorimeter_go_up] - der_ring_des_nibelungen >= k) {
            ++the_local_population_of_hippopotami;
            der_ring_des_nibelungen = where_do_the_hippopotami_rest [calorimeter_go_up];
        }
    }

    std::cout << the_local_population_of_hippopotami;

    return 0;
}