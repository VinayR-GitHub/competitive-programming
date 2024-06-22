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
        std::string bin; std::cin >> bin;
        int count = 1;
        bool is_legit = false;
        for (int i = 0; i < bin.length() - 1; ++i) {
            if (bin [i] != bin [i + 1]) {
                if (bin [i] == 48) is_legit = true;
                ++count;
            }
        }
        if (is_legit) --count;
        if (count) std::cout << count << '\n';
    }

    return 0;
}