#include <iostream>
#include <vector>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

bool what_dir(int curc, int tarc) {
    if (curc > tarc) {
        return false;
    } else {
        return true;
    }
}

bool left_or_right(bool up_down, bool x_y, int cur_dir) {
    int new_dir = (x_y) ? ((up_down) ? 1 : 3) : ((up_down) ? 0 : 2);
    if ((new_dir - cur_dir) % 4 == 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    FILE(snake);
    int x, y; std::cin >> x >> y;
    std::vector<char> instructions;
    std::pair<int, int> coord = PAIR(0, 0); std::pair<int, int> target = PAIR(x, y);

    bool x_or_y = false; int cur_dir = 0; // North - 0, east - 1, south - 2, west - 3
    while (true) {
        if (coord == target) {
            break;
        }
        x_or_y = !x_or_y;
        instructions.push_back((left_or_right(what_dir(((x_or_y) ? coord.first : coord.second), ((x_or_y) ? target.first : target.second)), x_or_y, cur_dir)) ? 'R' : 'L');
        cur_dir += ((instructions.back() == 'R') ? 1 : -1);
        if (cur_dir == 4) {
            cur_dir == 0;
        }
        if (cur_dir == -1) {
            cur_dir == 3;
        }
        if ((x_or_y) ? what_dir(coord.first, target.first) : what_dir(coord.second, target.second)) {
            ++((x_or_y) ? coord.first : coord.second);
        } else {
            --((x_or_y) ? coord.first : coord.second);
        }
    }

    std::string str(instructions.begin(), instructions.end());
    std::cout << str;

    return 0;
}