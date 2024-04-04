#include <iostream>
#include <array>
#include <vector>
#include <climits>
#include <algorithm>

#define MIN std::min
#define MAX std::max
#define PAIR std::make_pair
#define FILE(id) \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    unsigned long long n, f;
    FILE(space);

    std::cin >> n >> f;

    auto portal_fuel_load = new int[n]{};

    std::vector<int> down_min_poses, up_min_poses;

    // We simultaneously run down from the left.
    int the_running_minimum_1 = INT_MAX;
    for (int it = 0; it < n; ++it) {
        std::cin >> portal_fuel_load [it];
        if (portal_fuel_load [it] < the_running_minimum_1) {
            the_running_minimum_1 = portal_fuel_load [it];
            down_min_poses.push_back(it);
        }
    }

    // Running down from the right.
    int the_running_minimum_2 = INT_MAX;
    for (int it = (n - 1); it >= 0; --it) {
        if (portal_fuel_load [it] < the_running_minimum_2) {
            the_running_minimum_2 = portal_fuel_load [it];
            up_min_poses.push_back(it);
        }
    }

    int the_max_days = -1;

    int ptr1 = 0;
    int max1 = down_min_poses.size();
    std::reverse(up_min_poses.begin(), up_min_poses.end());
    int ptr2 = 0;
    int max2 = up_min_poses.size();

    while (true) {
        if (portal_fuel_load [down_min_poses [ptr1]] + portal_fuel_load [up_min_poses [ptr2]] <= f) {
            the_max_days = MAX(up_min_poses [ptr2] - down_min_poses [ptr1] + 1, the_max_days);
            ++ptr2;
            if (ptr2 == max2) {
                break;
            }
        } else {
            ++ptr1;
            if (ptr1 == max1) {
                break;
            }
        }
    }

    if (the_max_days == 1) {
        the_max_days = -1;
    }
    std::cout << the_max_days;

    return 0;
}