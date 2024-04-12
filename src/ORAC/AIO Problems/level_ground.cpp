#include <iostream>
#include <vector>
#include <algorithm>

#define PB push_back
#define B begin
#define E end

int main() {
    int n, curalt;
    std::vector<int> maxes;
    freopen("groundin.txt", "r", stdin);
    freopen("groundout.txt", "w", stdout);

    std::cin >> n >> curalt;
    --n;
    int tot = curalt;
    while (n--) {
        int newalt;
        std::cin >> newalt;
        if (newalt == curalt) {
            tot += curalt;
        } else {
            curalt = newalt;
            maxes.PB(tot);
            tot = curalt;
        }
    }
    maxes.PB(tot);
    
    std::cout << *std::max_element(maxes.B(), maxes.E());

    return 0;
}