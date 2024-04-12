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
    FILE(hand);
    int n, s, k; std::cin >> n >> s >> k;

    for (int i = 0; i < k; ++i) {
        int ai, bi; std::cin >> ai >> bi;
        if (s == ai) {
            s = bi;
        } else if (bi >= s && ai < s) {
            --s;
        } else if (ai > s && bi <= s) {
            ++s;
        }
    }

    std::cout << s;

    return 0;
}