#include <iostream>
#include <array>
#include <vector>

#define MIN std::min
#define MAX std::max
#define PAIR std::make_pair
#define BREAKZONE while (true)
#define LOOPZONE while (true)
#define INT_FOR(iter, bot_incl, top_excl) for (int iter = (bot_incl); iter < (top_excl); ++iter)
#define DOWN_INT_FOR(iter, top_incl, bot_excl) for (int iter = (top_incl); iter > (bot_excl); --iter)
#define FILE(id) \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

bool is_row(int index, int the_row, int cols) {
    // Let all items be from 0 to n - 1, not 1 to n.
    return (index / cols == the_row);
}
bool is_col(int index, int the_col, int cols) {
    return (index % cols == the_col);
}

int main() {
    int r, c;
    FILE(yalp);
    std::vector<std::vector<bool>> bit_arr;
    auto big_what_changes = new int[(int) 4e4]{}; // n = row_no * c + col_no

    std::cin >> r >> c;

    // Subtask 5 (i.e., all subtasks)
    INT_FOR(i, 0, r) {
        std::vector<bool> cur_arr;
        INT_FOR(j, 0, c) {
            char cond;
            std::cin >> cond;
            cur_arr.push_back(cond == '*');
        }
        bit_arr.push_back(cur_arr);
    }

    // Subtasks 1 & 2
    if (r % 2 == 0 && c % 2 == 0) {
        INT_FOR(i, 0, r) {
            INT_FOR(j, 0, c) {
                if (!bit_arr [i][j]) {
                    INT_FOR(rows_iter, 0, r) {
                        ++big_what_changes [rows_iter * c + j];
                    }
                    INT_FOR(cols_iter, 0, c) {
                        ++big_what_changes [i * c + cols_iter];
                    }
                    --big_what_changes [i * c + j];
                }
            }
        }
    }

    // Subtask 3
    // Subtask 3A (described subtask)
    if (r % 2 == 1 && c % 2 == 0) {
        INT_FOR(j, 0, c) {
            INT_FOR(i, 0, (r - 1)) {
                if (!bit_arr [i][j]) {
                    // If the square is unlit, commit a square swap.
                    bit_arr [i][j] = !bit_arr [i][j];
                    bit_arr [i + 1][j] = !bit_arr [i + 1][j];
                    INT_FOR(cols_iter, 0, c) {
                        ++big_what_changes [i * c + cols_iter];
                        ++big_what_changes [(i + 1) * c + cols_iter];
                    }
                    --big_what_changes [i * c + j];
                    --big_what_changes [(i + 1) * c + j];
                }
            }
        }
        bool the_thing = bit_arr [r - 1][0];
        INT_FOR(cols_iter, 1, c) {
            if (bit_arr [r - 1][cols_iter] != the_thing) {
                std::cout << "-1";
                return 0; // This is IMPOSSIBLE!
            }
        }
        if (the_thing) {
            ; // This works, because all squares are lit.
        } else {
            INT_FOR(cols_iter, 0, (c - 1)) {
                ++big_what_changes [(r - 1) * c + cols_iter];
            }
            INT_FOR(rows_iter, 0, (r - 1)) {
                ++big_what_changes [rows_iter * c + c - 1];
            }
        }
    }
    // Subtask 3B (minor extension)
    if (r % 2 == 0 && c % 2 == 1) {
        INT_FOR(i, 0, r) {
            INT_FOR(j, 0, (c - 1)) {
                if (!bit_arr [i][j]) {
                    // If the square is unlit, commit a square swap.
                    bit_arr [i][j] = !bit_arr [i][j];
                    bit_arr [i][j + 1] = !bit_arr [i][j + 1];
                    INT_FOR(rows_iter, 0, r) {
                        ++big_what_changes [rows_iter * c + j];
                        ++big_what_changes [rows_iter * c + j + 1];
                    }
                    --big_what_changes [i * c + j];
                    --big_what_changes [i * c + j + 1];
                }
            }
        }
        bool the_thing = bit_arr [0][c - 1];
        INT_FOR(rows_iter, 1, r) {
            if (bit_arr [rows_iter][c - 1] != the_thing) {
                std::cout << "-1";
                return 0; // This is IMPOSSIBLE!
            }
        }
        if (the_thing) {
            ; // This works, because all squares are lit.
        } else {
            INT_FOR(rows_iter, 0, (r - 1)) {
                ++big_what_changes [rows_iter * c + c - 1];
            }
            INT_FOR(cols_iter, 0, (c - 1)) {
                ++big_what_changes [(r - 1) * c + cols_iter];
            }
        }
    }

    // Subtask 4
    if (r % 2 == 1 && c % 2 == 1) {
        INT_FOR(i, 0, r - 1) {
            INT_FOR(j, 0, c - 1) {
                if (!bit_arr [i][j]) {
                    INT_FOR(rows_iter, 0, r - 1) {
                        ++big_what_changes [rows_iter * c + j];
                        bit_arr [rows_iter][c - 1] = !bit_arr [rows_iter][c - 1];
                    }
                    INT_FOR(cols_iter, 0, c - 1) {
                        ++big_what_changes [i * c + cols_iter];
                        bit_arr [r - 1][cols_iter] = !bit_arr [r - 1][cols_iter];
                    }
                    --big_what_changes [i * c + j];
                    bit_arr [i][c - 1] = !bit_arr [i][c - 1];
                    bit_arr [r - 1][j] = !bit_arr [r - 1][j];
                }
            }
        }
        bool the_thing = bit_arr [0][c - 1];
        INT_FOR(rows_iter, 1, r) {
            if (bit_arr [rows_iter][c - 1] != the_thing) {
                std::cout << "-1";
                return 0; // This is IMPOSSIBLE!
            }
        }
        INT_FOR(cols_iter, 0, c - 1) {
            if (bit_arr [r - 1][cols_iter] != the_thing) {
                std::cout << "-1";
                return 0; // This is IMPOSSIBLE!
            }
        }
        if (the_thing) {
            ; // This works, because all squares are lit.
        } else {
            ++big_what_changes [(r * c) - 1];
        }
    }

    // Subtask 5 (i.e., all subtasks)
    int changes_num = 0;
    std::vector<std::pair<int, int>> my_changes;
    INT_FOR(iter, 0, (r * c)) {
        if (big_what_changes[iter] % 2 == 1) {
            ++changes_num;
            my_changes.push_back(PAIR(iter / c, iter % c));
        }
    }
    std::cout << changes_num;
    for (auto& pair_item : my_changes) {
        std::cout << '\n' << pair_item.first << ' ' << pair_item.second;
    }

    return 0;
}