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
    std::deque<char> match;
    char bracket;
    for (int i = 0; i < n; ++i) {
        std::cin >> bracket;
        switch (bracket) {
            case '(':
            case '[':
            case '{':
                match.push_front(bracket);
                break;
            case ')':
                if (match.front() == '(') {
                    match.pop_front();
                } else {
                    std::cout << "NO";
                    return 0;
                }
                break;
            case ']':
                if (match.front() == '[') {
                    match.pop_front();
                } else {
                    std::cout << "NO";
                    return 0;
                }
                break;
            case '}':
                if (match.front() == '{') {
                    match.pop_front();
                } else {
                    std::cout << "NO";
                    return 0;
                }
                break;
        }
    }

    if (match.size()) std::cout << "NO";
    else std::cout << "YES";
    return 0;
}