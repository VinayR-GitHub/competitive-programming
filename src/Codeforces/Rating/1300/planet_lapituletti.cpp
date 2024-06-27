#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define ACCEL() \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL);

int main() {
    int t; std::cin >> t;
    while (t--) {
        int h, m; std::cin >> h >> m;
        std::string hhmm; std::cin >> hhmm;
        int hh = std::stoi(hhmm.substr(0, 2));
        int mm = std::stoi(hhmm.substr(3, 2));

        int* t = new int[h * m]{};
        for (int hr = 0; hr < h; ++hr) {
            for (int min = 0; min < m; ++min) {
                int h1 = hr % 10;
                int h2 = hr / 10;

                int m1 = min % 10;
                int m2 = min / 10;

                if (h1 == 0 || h1 == 1 || h1 == 2 || h1 == 5 || h1 == 8) {
                    if (h1 == 2) h1 = 5;
                    else if (h1 == 5) h1 = 2;

                    if (h2 == 0 || h2 == 1 || h2 == 2 || h2 == 5 || h2 == 8) {
                        if (h2 == 2) h2 = 5;
                        else if (h2 == 5) h2 = 2;

                        if (m1 == 0 || m1 == 1 || m1 == 2 || m1 == 5 || m1 == 8) {
                            if (m1 == 2) m1 = 5;
                            else if (m1 == 5) m1 = 2;

                            if (m2 == 0 || m2 == 1 || m2 == 2 || m2 == 5 || m2 == 8) {
                                if (m2 == 2) m2 = 5;
                                else if (m2 == 5) m2 = 2;

                                if (h1 * 10 + h2 < m) {
                                    if (m1 * 10 + m2 < h) {
                                        t [hr * m + min] = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        int iter = hh * m + mm;
        while (true) {
            if (t [iter]) break;
            ++iter;
            if (iter == h * m) {
                iter = 0;
            }
        }

        mm = iter % m;
        hh = iter / m;

        std::string res;
        if (hh < 10) res += '0';
        res += std::to_string(hh);
        res += ':';
        if (mm < 10) res += '0';
        res += std::to_string(mm);

        std::cout << res << '\n';
    }

    return 0;
}