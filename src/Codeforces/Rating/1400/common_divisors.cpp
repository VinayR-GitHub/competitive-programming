#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int n1 = s1.length();
    int n2 = s2.length();
    int* divisors = new int[MAX(n1, n2)]{};
    for (int i = 1; i <= n1; ++i) {
        if (n1 % i == 0) {
            ++divisors [i - 1];
        }
    }
    for (int i = 1; i <= n2; ++i) {
        if (n2 % i == 0) {
            divisors [i - 1] += 2;
        }
    }
    int num = 0;
    for (int i = 1; i <= MAX(n1, n2); ++i) {
        if (divisors [i - 1] != 3) continue;
        std::string copy = s1.substr(0, i);
        bool can = true;
        for (int j = 1; j < n1 / i; ++j) {
            std::string compar = s1.substr(j * i, i);
            if (copy != compar) {
                can = false;
                break;
            }
        }
        if (!can) continue;
        for (int j = 0; j < n2 / i; ++j) {
            std::string compar = s2.substr(j * i, i);
            if (copy != compar) {
                can = false;
                break;
            }
        }
        if (can) ++ num;
    }
    std::cout << num;
    return 0;
}