#include <iostream>
#include <array>
#include <limits.h>

int main() {
    int n, k;
    freopen("rafflein.txt", "r", stdin);
    freopen("raffleout.txt", "w", stdout);

    std::cin >> n >> k;
    auto arr = new int[k]{};
    while (n--) {
        int val;
        std::cin >> val;
        ++arr [val - 1];
    }

    int output;
    for (int it = 0; it < k; ++it) {
        if (arr [it] == 1) {
            output = it + 1;
            break;
        }
        if (it == (k - 1)) {
            output = -1;
        }
    }

    std::cout << output;

    return 0;
}