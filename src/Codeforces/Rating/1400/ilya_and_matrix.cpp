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
    int expn4; std::cin >> expn4;
    int* a = new int[expn4]{};
    for (int i = 0; i < expn4; ++i) {
        std::cin >> a [i];
    }
    std::sort(a, a + expn4, std::greater<int>());
    int num = 0;
    int texpn4 = expn4;
    while (texpn4) {
        texpn4 >>= 2;
        ++num;
    }
    int maxseed = 1;
    long long tot = 0LL;
    for (int i = 0; i < num; ++i) {
        for (int j = maxseed >> 2; j < maxseed; ++j) {
            tot += 1LL * (num - i) * a [j];
        }
        maxseed <<= 2;
    }
    std::cout << tot;
    return 0;
}