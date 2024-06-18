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
    int n, d; std::cin >> n >> d;

    std::vector<int>* adj = new std::vector<int>[9]{};
    adj [0].push_back(1);
    adj [0].push_back(3);
    adj [1].push_back(0);
    adj [1].push_back(2);
    adj [1].push_back(4);
    adj [2].push_back(1);
    adj [2].push_back(5);
    adj [3].push_back(0);
    adj [3].push_back(4);
    adj [3].push_back(6);
    adj [4].push_back(1);
    adj [4].push_back(3);
    adj [4].push_back(5);
    adj [4].push_back(7);
    adj [5].push_back(2);
    adj [5].push_back(4);
    adj [5].push_back(8);
    adj [6].push_back(3);
    adj [6].push_back(7);
    adj [7].push_back(4);
    adj [7].push_back(6);
    adj [7].push_back(8);
    adj [8].push_back(5);
    adj [8].push_back(7);

    int* mm = new int[9 * n + 9]{};
    std::function<int(int, int)> recurse;
    recurse = [&](int digit, int num)->int {
        if (num == 1) return 1;
        if (mm [9 * num + digit]) return mm [9 * num + digit];
        int tot = 0;
        for (auto& val : adj [digit]) {
            tot += recurse(val, num - 1);
        }
        mm [9 * num + digit] = tot % 1000003;
        return tot % 1000003;
    };

    std::cout << recurse(d - 1, n);
    return 0;
}