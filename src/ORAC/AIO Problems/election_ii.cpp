#include <iostream>

int main() {
    int n;
    int a = 0;
    int b = 0;
    int c = 0;
    freopen("elecin.txt", "r", stdin);
    freopen("elecout.txt", "w", stdout);

    std::cin >> n;
    while (n--) {
        char ch;
        std::cin >> ch;
        switch (ch) {
            case 'A':
                ++a;
                break;
            case 'B':
                ++b;
                break;
            case 'C':
                ++c;
                break;
        }
    }

    if (a > b && a > c) {
        std::cout << "A";
    } else if (b > a && b > c) {
        std::cout << "B";
    } else if (c > a && c > b) {
        std::cout << "C";
    } else {
        std::cout << "T";
    }

    return 0;
}