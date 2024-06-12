#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(pow2);
    std::string check; std::cin >> check;
    std::reverse(check.begin(), check.end());

    int ans = 0;
    std::string num = "1";
    if (num.find(check) != std::string::npos) goto PRINT;

    for (ans = 1; ans < 10000; ++ans) {
        int carrier = 0;
        for (int i = 0; i < num.length(); ++i) {
            carrier += 2 * (static_cast<int>(num [i]) - 48);
            num [i] = static_cast<char>(carrier % 10 + 48);
            carrier /= 10;
        }
        if (carrier) num += '1';
        if (num.find(check) != std::string::npos) goto PRINT;
    }

    PRINT:
        if (ans == 10000) std::cout << "No solution found";
        else std::cout << ans;

    return 0;
}