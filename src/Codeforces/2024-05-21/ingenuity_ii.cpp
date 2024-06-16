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
        int num; std::cin >> num;
        std::string instructions; std::cin >> instructions;
        int n = 0; int s = 0; int e = 0; int w = 0;
        for (int i = 0; i < num; ++i) {
            switch (instructions [i]) {
                case 'N':
                    ++n;
                    break;
                case 'S':
                    ++s;
                    break;
                case 'E':
                    ++e;
                    break;
                case 'W':
                    ++w;
                    break;
            }
        }
        if ((n + s) & 1 || (e + w) & 1) {
            std::cout << "NO\n";
            continue;
        }
        if (num == 2) {
            if (instructions [0] != instructions [1]) {
                std::cout << "NO\n";
                continue;
            }
        }
        std::string res = "";
        std::pair<int, int> end = PAIR((n - s) >> 1, (e - w) >> 1);
        std::pair<int, int> curr = PAIR(0, 0);
        std::pair<int, int> curi = PAIR(0, 0);
        bool has_heli = false;
        bool has_rove = false;
        for (int i = 0; i < num; ++i) {
            switch (instructions [i]) {
                case 'N':
                    if (curr.first < end.first) {
                        ++curr.first;
                        res += 'R';
                    } else if (curi.first < end.first) {
                        ++curi.first;
                        res += 'H';
                    } else {
                        if (!has_rove) {
                            ++curr.first;
                            res += 'R';
                            has_rove = true;
                        } else {
                            ++curi.first;
                            res += 'H';
                            has_heli = true;
                        }
                    }
                    break;
                case 'S':
                    if (curr.first > end.first) {
                        --curr.first;
                        res += 'R';
                    } else if (curi.first > end.first) {
                        --curi.first;
                        res += 'H';
                    } else {
                        if (!has_rove) {
                            --curr.first;
                            res += 'R';
                            has_rove = true;
                        } else {
                            --curi.first;
                            res += 'H';
                            has_heli = true;
                        }
                    }
                    break;
                case 'E':
                    if (curr.second < end.second) {
                        ++curr.second;
                        res += 'R';
                    } else if (curi.second < end.second) {
                        ++curi.second;
                        res += 'H';
                    } else {
                        if (!has_rove) {
                            ++curr.second;
                            res += 'R';
                            has_rove = true;
                        } else {
                            ++curi.second;
                            res += 'H';
                            has_heli = true;
                        }
                    }
                    break;
                case 'W':
                    if (curr.second > end.second) {
                        --curr.second;
                        res += 'R';
                    } else if (curi.second > end.second) {
                        --curi.second;
                        res += 'H';
                    } else {
                        if (!has_rove) {
                            --curr.second;
                            res += 'R';
                            has_rove = true;
                        } else {
                            --curi.second;
                            res += 'H';
                            has_heli = true;
                        }
                    }
                    break;
            }
        }
        std::cout << res << '\n';
    }

    return 0;
}