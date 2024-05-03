#include <iostream>
#include <array>

#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(pal);
    int n; std::cin >> n;
    char* txt = new char[n]{}; for (int i = 0; i < n; ++i) std::cin >> txt [i];
    for (int i = 0; i < (n / 2); ++i) {
        if (txt [i] != txt [n - i - 1]) {
            txt [i] = std::min(txt [i], txt [n - i - 1]);
            txt [n - i - 1] = txt [i];
        }
    }

    for (int i = 0; i < n; ++i) std::cout << txt [i];

    return 0;
}