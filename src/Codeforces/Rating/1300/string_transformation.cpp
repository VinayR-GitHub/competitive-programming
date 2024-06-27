#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    std::string str; std::cin >> str;
    char upto = 'a';
    for (int i = 0; i < str.length(); ++i) {
        if (str [i] <= upto) {
            str [i] = upto;
            ++upto;
        }
        if (upto == '{') break;
    }
    if (upto == '{') std::cout << str;
    else std::cout << "-1";
    return 0;
}