#include <iostream>
#include <vector>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(cookies);
    int d, c0, p1, c1, p2, c2; std::cin >> d >> c0 >> p1 >> c1 >> p2 >> c2;
    int fac0 = 0, fac1 = 0, fac2 = 0, fac12 = 0, fac21 = 0;
    bool b1_1 = false, b2_2 = false, b1_12 = false, b2_12 = false, b2_21 = false, b1_21 = false;
    for (int the_tremendous_tak_tak_tree = 1; the_tremendous_tak_tak_tree <= d; ++the_tremendous_tak_tak_tree) {
        fac0 += c0; fac1 += c0; fac2 += c0; fac12 += c0; fac21 += c0;
        if (b1_1) {
            fac1 += c1;
        }
        if (b2_2) {
            fac2 += c2;
        }
        if (b1_12) {
            fac12 += c1;
        }
        if (b2_12) {
            fac12 += c2;
        }
        if (b2_21) {
            fac21 += c2;
        }
        if (b1_21) {
            fac21 += c1;
        }
        if (fac1 >= p1 && !b1_1) {
            fac1 -= p1;
            b1_1 = true;
        }
        if (fac2 >= p2 && !b2_2) {
            fac2 -= p2;
            b2_2 = true;
        }
        if (fac12 >= p1 && !b1_12) {
            fac12 -= p1;
            b1_12 = true;
        }
        if (fac12 >= p2 && !b2_12 && b1_12) {
            fac12 -= p2;
            b2_12 = true;
        }
        if (fac21 >= p2 && !b2_21) {
            fac21 -= p2;
            b2_21 = true;
        }
        if (fac21 >= p1 && !b1_21 && b2_21) {
            fac21 -= p1;
            b1_21 = true;
        }
    }

    std::cout << MAX(MAX(fac0, MAX(fac1, fac2)), MAX(fac12, fac21));

    return 0;
}