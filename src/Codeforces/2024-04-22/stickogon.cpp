#include <iostream>
#include <array>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;
    while (t--) {
        int* count = new int[100]{};
        int n; std::cin >> n; int temp;
        for (int i = 0; i < n; ++i) std::cin >> temp, ++count [temp - 1];
        int num = 0;
        for (int i = 0; i < 100; ++i) num += (count [i] / 3);
        std::cout << num << '\n';
    }

    return 0;
}