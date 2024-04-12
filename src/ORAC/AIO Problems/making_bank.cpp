#include <iostream>
#include <array>

int main() {
    int n;
    std::string val_list;
    freopen("bankin.txt", "r", stdin);
    freopen("bankout.txt", "w", stdout);

    std::cin >> n >> val_list;
    auto arr = new bool[n]{};
    int s = 1;
    int curval = 0;
    for (int it = 0; it < n; ++it) {
        if (val_list [it] == 'C') {
            arr [it] = true;
            ++s;
        } else {
            curval += s;
            arr [it] = false;
        }
    }

    int max = curval;
    int iter = n;
    int fols = 0;

    while (iter--) {
        if (arr [iter]) {
            --s;
            curval += s;
            curval -= fols;
            if (curval < max) {
                break;
            } else {
                max = curval;
            }
        }
        ++fols;
    }

    std::cout << max;

    return 0;
}