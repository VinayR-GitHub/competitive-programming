#include <iostream>

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
    FILE(rps);

    int n, ra, rb, pa, pb, sa, sb; std::cin >> n >> ra >> pa >> sa >> rb >> pb >> sb;

    int pts = 0;

    if (ra <= pb) {
        pb -= ra;
        pts += ra;
    } else {
        if (ra - pb <= rb) {
            rb -= ra;
            rb += pb;
            pts += pb;
        } else {
            int temp = sb;
            sb -= ra;
            sb += pb;
            sb += rb;
            pts += pb; pts -= temp; pts += sb;
            rb = 0;
        }
        pb = 0;
    }

    if (pa <= sb) {
        sb -= pa;
        pts += pa;
    } else {
        if (pa - sb <= pb) {
            pb -= pa;
            pb += sb;
            pts += sb;
        } else {
            int temp = rb;
            rb -= pa;
            rb += sb;
            rb += pb;
            pts += sb; pts -= temp; pts += rb;
            pb = 0;
        }
        sb = 0;
    }

    if (sa <= rb) {
        rb -= sa;
        pts += sa;
    } else {
        if (sa - rb <= sb) {
            sb -= sa;
            sb += rb;
            pts += rb;
        } else {
            int temp = pb;
            pb -= sa;
            pb += rb;
            pb += sb;
            pts += rb; pts -= temp; pts += pb;
            sb = 0;
        }
        rb = 0;
    }

    std::cout << pts;

    return 0;
}