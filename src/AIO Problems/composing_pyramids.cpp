#include <iostream>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(comp);

    int n; std::cin >> n;
    auto keys = new int[n]{}, llens = new int[n]{}, rlens = new int[n]{};
    auto jlstor = new int[(int) 1e5+1]{}, jrstor = new int[(int) 1e5+1]{};
    
    llens [0] = 1; rlens [n - 1] = 1;
    std::cin >> keys [0]; jlstor [keys [0]] = 1;
    for (int i = 1; i < n; ++i) std::cin >> keys [i], llens [i] = jlstor [keys [i] - 1] + 1, jlstor [keys [i]] = llens [i];
    jrstor [keys [n-1]] = 1;
    for (int j = n - 2; j > -1; --j) rlens [j] = jrstor [keys [j] - 1] + 1, jrstor [keys [j]] = rlens [j];

    int the_pyramid_of_giza = 0;
    for (int top = 0; top < n; ++top) the_pyramid_of_giza = MAX(the_pyramid_of_giza, MIN(llens [top], rlens [top]));

    std::cout << (n - (2 * the_pyramid_of_giza) + 1);

    return 0;
}