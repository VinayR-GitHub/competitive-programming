#include <iostream>
#include <array>
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
    FILE(janitor);
    int r, c, q; std::cin >> r >> c >> q;
    int* tiles = new int[r * c]{}; int* spots = new int[r * c]{}; // R : C ordering.
    for (int i = 0; i < (r * c); ++i) std::cin >> tiles [i];
    int num = 0; for (int row = 0; row < r; ++row) {
        bool top = row == 0; bool bottom = row == (r - 1);
        for (int col = 0; col < c; ++col) {
            bool left = col == 0; bool right = col == (c - 1);
            if (((bottom) ? true : tiles [row * c + col] > tiles [(row + 1) * c + col]) && ((top) ? true : tiles [row * c + col] > tiles [(row - 1) * c + col]) && ((right) ? true : tiles [row * c + col] > tiles [row * c + (col + 1)]) && ((left) ? true : tiles [row * c + col] > tiles [row * c + (col - 1)])) {
                ++num;
                ++spots [row * c + col];
            }
        }
    }

    std::cout << num;
    
    for (int i = 0; i < q; ++i) {
        int ri, ci, hi; std::cin >> ri >> ci >> hi;
        --ri; --ci;
        tiles [ri * c + ci] = hi;

        bool top = ri == 0; bool bottom = ri == (r - 1); bool left = ci == 0; bool right = ci == (c - 1);
        bool stop = top; bool sbot = bottom; bool slef = left; bool srig = right;

        if (((bottom) ? true : tiles [ri * c + ci] > tiles [(ri + 1) * c + ci]) && ((top) ? true : tiles [ri * c + ci] > tiles [(ri - 1) * c + ci]) && ((right) ? true : tiles [ri * c + ci] > tiles [ri * c + (ci + 1)]) && ((left) ? true : tiles [ri * c + ci] > tiles [ri * c + (ci - 1)])) {
            if (spots [ri * c + ci]) {
                ;
            } else {
                ++num;
                ++spots [ri * c + ci];
            }
        } else {
            if (spots [ri * c + ci]) {
                --spots [ri * c + ci];
                --num;
            }
        }

        --ri;
        if (!stop) {
            top = ri == 0; bottom = ri == (r - 1); left = ci == 0; right = ci == (c - 1);
            if (((bottom) ? true : tiles [ri * c + ci] > tiles [(ri + 1) * c + ci]) && ((top) ? true : tiles [ri * c + ci] > tiles [(ri - 1) * c + ci]) && ((right) ? true : tiles [ri * c + ci] > tiles [ri * c + (ci + 1)]) && ((left) ? true : tiles [ri * c + ci] > tiles [ri * c + (ci - 1)])) {
                if (spots [ri * c + ci]) {
                    ;
                } else {
                    ++num;
                    ++spots [ri * c + ci];
                }
            } else {
                if (spots [ri * c + ci]) {
                    --spots [ri * c + ci];
                    --num;
                }
            }
        }

        ri += 2;
        if (!sbot) {
            top = ri == 0; bottom = ri == (r - 1); left = ci == 0; right = ci == (c - 1);
            if (((bottom) ? true : tiles [ri * c + ci] > tiles [(ri + 1) * c + ci]) && ((top) ? true : tiles [ri * c + ci] > tiles [(ri - 1) * c + ci]) && ((right) ? true : tiles [ri * c + ci] > tiles [ri * c + (ci + 1)]) && ((left) ? true : tiles [ri * c + ci] > tiles [ri * c + (ci - 1)])) {
                if (spots [ri * c + ci]) {
                    ;
                } else {
                    ++num;
                    ++spots [ri * c + ci];
                }
            } else {
                if (spots [ri * c + ci]) {
                    --spots [ri * c + ci];
                    --num;
                }
            }
        }
        
        --ri; --ci;
        if (!slef) {
            top = ri == 0; bottom = ri == (r - 1); left = ci == 0; right = ci == (c - 1);
            if (((bottom) ? true : tiles [ri * c + ci] > tiles [(ri + 1) * c + ci]) && ((top) ? true : tiles [ri * c + ci] > tiles [(ri - 1) * c + ci]) && ((right) ? true : tiles [ri * c + ci] > tiles [ri * c + (ci + 1)]) && ((left) ? true : tiles [ri * c + ci] > tiles [ri * c + (ci - 1)])) {
                if (spots [ri * c + ci]) {
                    ;
                } else {
                    ++num;
                    ++spots [ri * c + ci];
                }
            } else {
                if (spots [ri * c + ci]) {
                    --spots [ri * c + ci];
                    --num;
                }
            }
        }

        ci += 2;
        if (!srig) {
            top = ri == 0; bottom = ri == (r - 1); left = ci == 0; right = ci == (c - 1);
            if (((bottom) ? true : tiles [ri * c + ci] > tiles [(ri + 1) * c + ci]) && ((top) ? true : tiles [ri * c + ci] > tiles [(ri - 1) * c + ci]) && ((right) ? true : tiles [ri * c + ci] > tiles [ri * c + (ci + 1)]) && ((left) ? true : tiles [ri * c + ci] > tiles [ri * c + (ci - 1)])) {
                if (spots [ri * c + ci]) {
                    ;
                } else {
                    ++num;
                    ++spots [ri * c + ci];
                }
            } else {
                if (spots [ri * c + ci]) {
                    --spots [ri * c + ci];
                    --num;
                }
            }
        }

        std::cout << '\n' << num;
    }

    return 0;
}