#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    ACCEL();
    int t; std::cin >> t;
    while (t--) {
        std::string time; std::cin >> time;
        int hour = std::stoi(time.substr(0, 2));
        bool ist = true;
        if (hour < 12) ist = false;
        hour = hour % 12;
        if (!hour) hour = 12;
        if (hour < 10) std::cout << '0';
        std::cout << hour << time.substr(2, 3) << ' ' << (ist ? "PM\n" : "AM\n");
    }

    return 0;
}