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
    std::string s;
    std::cin >> s;
    int* dist = new int[26]{};
    for (int i = 0; i < s.length(); ++i) {
        ++dist [s [i] - 'A'];
    }
    int* left = new int[26]{};
    int* right = new int[26]{};
    std::vector<std::pair<int, char>> oddquant;
    for (int i = 0; i < 26; ++i) {
        if (dist [i] & 1) {
            oddquant.push_back(PAIR(dist [i], i + 'A'));
            continue;
        }
        left [i] = dist [i] >> 1;
        right [i] = dist [i] >> 1;
    }
    if (oddquant.size() > 1) {
        std::cout << "NO SOLUTION";
    } else {
        for (int j = 0; j < 26; ++j) {
            while (left [j]--) {
                std::cout << static_cast<char>('A' + j);
            }
        }
        if (oddquant.size()) {
            while (oddquant.back().first--) {
                std::cout << oddquant.back().second;
            }
        }
        for (int j = 25; j >= 0; --j) {
            while (right [j]--) {
                std::cout << static_cast<char>('A' + j);
            }
        }
    }
    return 0;
}