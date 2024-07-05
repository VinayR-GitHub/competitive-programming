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
    int w, h; std::cin >> w >> h;
    char* map = new char[w * h]{};
    std::pair<int, int> coord;
    for (int i = 0; i < h * w; ++i) {
        std::cin >> map [i];
        if (map [i] == 'U') {
            coord = PAIR(i / w, i % w);
        }
    }
    short* include = new short[w * h]{};
    include [coord.first * w + coord.second] = 1;
    int p; std::cin >> p;
    char* dir = new char[p]{};
    for (int i = 0; i < p; ++i) {
        std::cin >> dir [i];
    }
    std::reverse(dir, dir + p);
    for (int k = 0; k < p; ++k) {
        short* newinclude = new short[w * h]{};
        switch (dir [k]) {
            case 'N':
                for (int i = 0; i < h; ++i) {
                    for (int j = 0; j < w; ++j) {
                        if (!include [i * w + j]) continue;
                        if (i != h - 1) {
                            if (map [(i + 1) * w + j] != 'T') {
                                newinclude [(i + 1) * w + j] = 1;
                            }
                        }
                        if (i) {
                            if (map [(i - 1) * w + j] == 'T') {
                                newinclude [i * w + j] = 1;
                            }
                        } else {
                            newinclude [i * w + j] = 1;
                        }
                    }
                }
                break;
            case 'E':
                for (int i = 0; i < h; ++i) {
                    for (int j = 0; j < w; ++j) {
                        if (!include [i * w + j]) continue;
                        if (j) {
                            if (map [i * w + j - 1] != 'T') {
                                newinclude [i * w + j - 1] = 1;
                            }
                        }
                        if (j != w - 1) {
                            if (map [i * w + j + 1] == 'T') {
                                newinclude [i * w + j] = 1;
                            }
                        } else {
                            newinclude [i * w + j] = 1;
                        }
                    }
                }
                break;
            case 'S':
                for (int i = 0; i < h; ++i) {
                    for (int j = 0; j < w; ++j) {
                        if (!include [i * w + j]) continue;
                        if (i) {
                            if (map [(i - 1) * w + j] != 'T') {
                                newinclude [(i - 1) * w + j] = 1;
                            }
                        }
                        if (i != h - 1) {
                            if (map [(i + 1) * w + j] == 'T') {
                                newinclude [i * w + j] = 1;
                            }
                        } else {
                            newinclude [i * w + j] = 1;
                        }
                    }
                }
                break;
            case 'W':
                for (int i = 0; i < h; ++i) {
                    for (int j = 0; j < w; ++j) {
                        if (!include [i * w + j]) continue;
                        if (j != w - 1) {
                            if (map [i * w + j + 1] != 'T') {
                                newinclude [i * w + j + 1] = 1;
                            }
                        }
                        if (j) {
                            if (map [i * w + j - 1] == 'T') {
                                newinclude [i * w + j] = 1;
                            }
                        } else {
                            newinclude [i * w + j] = 1;
                        }
                    }
                }
                break;
        }
        for (int i = 0; i < h * w; ++i) {
            include [i] = newinclude [i];
        }
    }
    int count = 0;
    for (int i = 0; i < h * w; ++i) {
        count += include [i];
    }
    std::cout << count;
    return 0;
}