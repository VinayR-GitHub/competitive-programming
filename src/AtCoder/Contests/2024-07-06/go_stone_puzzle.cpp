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
    int n; std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    s += '.';
    s += '.';
    t += '.';
    t += '.';

    std::function<int(std::string&)> hash;
    hash = [](std::string& state)->int {
        int num = 0;
        int multip = 1;
        for (int i = 0; i < state.length(); ++i) {
            switch (state [i]) {
                case 'B':
                    num += multip;
                    break;
                case 'W':
                    num += multip * 2;
                    break;
                case '.':
                    break;
            }
            multip *= 3;
        }
        return num;
    };

    std::function<std::string(int)> parse;
    parse = [n](int num)->std::string {
        std::string state = "";
        for (int i = 0; i < n + 2; ++i) {
            switch (num % 3) {
                case 0:
                    state += '.';
                    break;
                case 1:
                    state += 'B';
                    break;
                case 2:
                    state += 'W';
                    break;
            }
            num /= 3;
        }
        return state;
    };

    short* visited = new short[43046721]{};
    int start = hash(s);
    int end = hash(t);
    int count = -1;
    std::deque<int> bfs;
    bfs.push_back(start);
    while (bfs.size()) {
        if (visited [end]) break;
        int num = bfs.size();
        while (num--) {
            int node = bfs.front();
            bfs.pop_front();
            if (visited [node]) continue;
            visited [node] = 1;
            std::string meaning = parse(node);
            int emptystart = 0;
            for (int i = 0; i < n + 1; ++i) {
                if (meaning [i] == '.') {
                    emptystart = i;
                    break;
                }
            }
            for (int i = 0; i < n + 1; ++i) {
                if (meaning [i] != '.' && meaning [i + 1] != '.') {
                    meaning [emptystart] = meaning [i];
                    meaning [emptystart + 1] = meaning [i + 1];
                    meaning [i] = '.';
                    meaning [i + 1] = '.';
                    bfs.push_back(hash(meaning));
                    meaning [i] = meaning [emptystart];
                    meaning [i + 1] = meaning [emptystart + 1];
                    meaning [emptystart] = '.';
                    meaning [emptystart + 1] = '.';
                }
            }
        }
        ++count;
    }
    if (visited [end]) {
        std::cout << count;
    } else {
        std::cout << "-1";
    }
    return 0;
}