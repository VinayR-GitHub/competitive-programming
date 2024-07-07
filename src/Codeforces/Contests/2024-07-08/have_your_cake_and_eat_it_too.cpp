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
        int n; std::cin >> n;
        int* a = new int[n]{};
        int* b = new int[n]{};
        int* c = new int[n]{};
        long long tot = 0LL;
        for (int i = 0; i < n; ++i) {
            std::cin >> a [i];
            tot += a [i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b [i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> c [i];
        }
        long long totdiv = tot / 3LL;
        if (tot % 3 != 0) ++totdiv;
        int r1;
        int l2;
        int r2;
        int l3;
        long long tot1 = 0LL;
        long long tot2 = 0LL;
        long long tot3 = 0LL;
        int ptr = 0;
        while (tot1 < totdiv) {
            tot1 += a [ptr];
            ++ptr;
        }
        r1 = ptr - 1;
        l2 = ptr;
        while (tot2 < totdiv && ptr < n) {
            tot2 += b [ptr];
            ++ptr;
        }
        if (ptr == n) {
            goto PERM2;
        }
        r2 = ptr - 1;
        l3 = ptr;
        while (ptr < n) {
            tot3 += c [ptr];
            ++ptr;
        }
        if (tot3 >= totdiv) {
            ++r1;
            ++l2;
            ++r2;
            ++l3;
            std::cout << "1 " << r1 << ' ';
            std::cout << l2 << ' ' << r2 << ' ';
            std::cout << l3 << ' ' << n << ' ';
            std::cout << '\n';
            goto NEXT;
        }
        PERM2:;
        tot1 = 0LL;
        tot2 = 0LL;
        tot3 = 0LL;
        ptr = 0;
        while (tot1 < totdiv) {
            tot1 += a [ptr];
            ++ptr;
        }
        r1 = ptr - 1;
        l2 = ptr;
        while (tot2 < totdiv && ptr < n) {
            tot2 += c [ptr];
            ++ptr;
        }
        if (ptr == n) {
            goto PERM3;
        }
        r2 = ptr - 1;
        l3 = ptr;
        while (ptr < n) {
            tot3 += b [ptr];
            ++ptr;
        }
        if (tot3 >= totdiv) {
            ++r1;
            ++l2;
            ++r2;
            ++l3;
            std::cout << "1 " << r1 << ' ';
            std::cout << l3 << ' ' << n << ' ';
            std::cout << l2 << ' ' << r2 << ' ';
            std::cout << '\n';
            goto NEXT;
        }
        PERM3:;
        tot1 = 0LL;
        tot2 = 0LL;
        tot3 = 0LL;
        ptr = 0;
        while (tot1 < totdiv) {
            tot1 += b [ptr];
            ++ptr;
        }
        r1 = ptr - 1;
        l2 = ptr;
        while (tot2 < totdiv && ptr < n) {
            tot2 += a [ptr];
            ++ptr;
        }
        if (ptr == n) {
            goto PERM4;
        }
        r2 = ptr - 1;
        l3 = ptr;
        while (ptr < n) {
            tot3 += c [ptr];
            ++ptr;
        }
        if (tot3 >= totdiv) {
            ++r1;
            ++l2;
            ++r2;
            ++l3;
            std::cout << l2 << ' ' << r2 << ' ';
            std::cout << "1 " << ' ' << r1 << ' ';
            std::cout << l3 << ' ' << n << ' ';
            std::cout << '\n';
            goto NEXT;
        }
        PERM4:;
        tot1 = 0LL;
        tot2 = 0LL;
        tot3 = 0LL;
        ptr = 0;
        while (tot1 < totdiv) {
            tot1 += b [ptr];
            ++ptr;
        }
        r1 = ptr - 1;
        l2 = ptr;
        while (tot2 < totdiv && ptr < n) {
            tot2 += c [ptr];
            ++ptr;
        }
        if (ptr == n) {
            goto PERM5;
        }
        r2 = ptr - 1;
        l3 = ptr;
        while (ptr < n) {
            tot3 += a [ptr];
            ++ptr;
        }
        if (tot3 >= totdiv) {
            ++r1;
            ++l2;
            ++r2;
            ++l3;
            std::cout << l3 << ' ' << n << ' ';
            std::cout << "1 " << r1 << ' ';
            std::cout << l2 << ' ' << r2 << ' ';
            std::cout << '\n';
            goto NEXT;
        }
        PERM5:;
        tot1 = 0LL;
        tot2 = 0LL;
        tot3 = 0LL;
        ptr = 0;
        while (tot1 < totdiv) {
            tot1 += c [ptr];
            ++ptr;
        }
        r1 = ptr - 1;
        l2 = ptr;
        while (tot2 < totdiv && ptr < n) {
            tot2 += a [ptr];
            ++ptr;
        }
        if (ptr == n) {
            goto PERM6;
        }
        r2 = ptr - 1;
        l3 = ptr;
        while (ptr < n) {
            tot3 += b [ptr];
            ++ptr;
        }
        if (tot3 >= totdiv) {
            ++r1;
            ++l2;
            ++r2;
            ++l3;
            std::cout << l2 << ' ' << r2 << ' ';
            std::cout << l3 << ' ' << n << ' ';
            std::cout << "1 " << r1 << ' ';
            std::cout << '\n';
            goto NEXT;
        }
        PERM6:;
        tot1 = 0LL;
        tot2 = 0LL;
        tot3 = 0LL;
        ptr = 0;
        while (tot1 < totdiv) {
            tot1 += c [ptr];
            ++ptr;
        }
        r1 = ptr - 1;
        l2 = ptr;
        while (tot2 < totdiv && ptr < n) {
            tot2 += b [ptr];
            ++ptr;
        }
        if (ptr == n) {
            std::cout << "-1\n";
            goto NEXT;
        }
        r2 = ptr - 1;
        l3 = ptr;
        while (ptr < n) {
            tot3 += a [ptr];
            ++ptr;
        }
        if (tot3 >= totdiv) {
            ++r1;
            ++l2;
            ++r2;
            ++l3;
            std::cout << l3 << ' ' << n << ' ';
            std::cout << l2 << ' ' << r2 << ' ';
            std::cout << "1 " << r1 << ' ';
            std::cout << '\n';
            goto NEXT;
        }
        std::cout << "-1\n";
        NEXT:;
    }
    return 0;
}