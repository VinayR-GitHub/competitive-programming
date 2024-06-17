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
        long long n, k; std::cin >> n >> k;
        int* a = new int[n]{};
        for (int i = 0; i < n; ++i) {
            a [i] = i + 1;
        }
        if (k & 1) {
            std::cout << "No\n";
            continue;
        }
        
        long long max = 0;
        for (int i = 0; i < n; ++i) {
            max += MAG(n - 2 * i - 1);
        }
        if (k > max) {
            std::cout << "No\n";
            continue;
        }
        std::cout << "Yes\n";
        
        int maxch = n - 1, ptr = 0;
        while (k > 2 * maxch) {
            std::swap(a [ptr], a [n - ptr - 1]);
            k -= maxch;
            k -= maxch;
            maxch -= 2;
            ++ptr;
        }
        std::swap(a [ptr], a [ptr + (k >> 1)]);

        for (int i = 0; i < n; ++i) {
            std::cout << a [i] << ' ';
        }
        std::cout << '\n';
    }
    
    return 0;
}