#include <iostream>
#include <limits.h>

int main() {
    int n;
    int cur = 0;
    int min = 0;
    int max = 0;
    freopen("telein.txt", "r", stdin);
    freopen("teleout.txt", "w", stdout);
    
    std::cin >> n;
    while (n--) {
        char c;
        std::cin >> c;
        switch (c) {
        case 'T':
            cur = 0;
            break;
        case 'L':
            --cur;
            break;
        case 'R':
            ++cur;
            break;
        }
        if (cur < min) {
            min = cur;
        }
        if (cur > max) {
            max = cur;
        }
    }

    std::cout << (max - min + 1);

    return 0;
}