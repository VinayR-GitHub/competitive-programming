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
    std::string input; std::cin >> input;
    std::vector<int> commas;
    commas.push_back(-1);
    int* is = new int[1002]{};
    for (int i = 0; i < input.length(); ++i) {
        if (input [i] == ',') {
            commas.push_back(i);
        }
    }
    commas.push_back(input.length());
    for (int i = 0; i < commas.size() - 1; ++i) {
        int num = std::stoi(input.substr(commas [i] + 1, commas [i + 1] - commas [i] - 1));
        is [num] = 1;
    }
    std::vector<int> tempstor;
    for (int i = 1; i < 1001; ++i) {
        if (is [i] && !is [i - 1]) tempstor.push_back(i);
        if (is [i] && !is [i + 1]) tempstor.push_back(i);
    }
    for (int i = 0; i < tempstor.size() >> 1; ++i) {
        if (i) std::cout << ',';
        if (tempstor [2 * i] == tempstor [2 * i + 1]) {
            std::cout << tempstor [2 * i];
        } else {
            std::cout << tempstor [2 * i] << '-' << tempstor [2 * i + 1];
        }
    }
    return 0;
}