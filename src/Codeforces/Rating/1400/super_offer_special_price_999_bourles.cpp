#include <bits/stdc++.h>
 
#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);
 
int main() {
    std::string p;
    long long d;
    std::cin >> p >> d;
    long long pint = std::stoll(p);
    std::reverse(p.begin(), p.end());
    long long low = pint - d;
    int num = p.length();
    int howmany9s;
    for (int i = 0; i < num; ++i) {
        if (p [i] != '9') {
            --num;
            howmany9s = i;
            break;
        }
    }
    if (num == p.length()) {
        std::reverse(p.begin(), p.end());
        std::cout << p;
        return 0;
    }
    std::vector<std::pair<int, long long>> bestchoices;
    bestchoices.push_back(PAIR(howmany9s, pint));
    for (int i = howmany9s;; ++i) {
        long long div = 1LL;
        for (int j = 0; j < i; ++j) div *= 10LL;
        pint /= div;
        pint *= div;
        --pint;
        if (pint < low) break;
        howmany9s = 0;
        long long stor = pint;
        while (stor % 10LL == 9) {
            ++howmany9s;
            stor /= 10LL;
        }
        bestchoices.push_back(PAIR(howmany9s, pint));
    }
    std::sort(bestchoices.begin(), bestchoices.end(), std::greater<std::pair<int, long long>>());
    std::cout << bestchoices [0].second;
    return 0;
}