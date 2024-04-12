#include <iostream>
#include <array>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

const char chars[5] = {'S', 'N', 'A', 'K', 'E'};

bool titanoboa(std::string snake_str, int venom) {
    int prog = 0, cind = 0;
    for (char& c : snake_str) {
        if (c == chars [cind]) {
            ++prog;
        }
        if (prog == venom) {
            ++cind;
            prog = 0;
            if (cind == 5) {
                return true;
            }
        }
    }
    return false;
}

int is_max(std::string snake_str, int venom) {
    return (bool) titanoboa(snake_str, venom) + (bool) titanoboa(snake_str, venom + 1);
}

int main() {
    FILE(snake);
    int n; std::cin >> n;
    std::string snake; std::cin >> snake;

    int low = 1; int high = (int) 2e4;
    while (!(high < low)) {
        int m_val = (low + high) >> 1;
        switch (is_max(snake, m_val)) {
            case 1:
                std::cout << m_val;
                return 0;
            case 2:
                low = m_val + 1;
                break;
            case 0:
                high = m_val - 1;
                break;
        }
    }

    std::cout << 0;

    return 0;
}