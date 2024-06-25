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
    std::string vk; std::cin >> vk;
    int n = vk.length();
    int* vks = new int[100]{};
    int* spv = new int[100]{};
    int* spk = new int[100]{};
    for (int i = 0; i < n - 1; ++i) {
        if (vk [i] == 'V' && vk [i + 1] == 'K') vks [i] = 1;
        if (vk [i] == 'V' && vk [i + 1] == 'V') spv [i] = 1;
        if (vk [i] == 'K' && vk [i + 1] == 'K') spk [i] = 1;
    }

    bool is_spare = false;
    for (int i = 0; i < n - 1; ++i) {
        if (spv [i]) {
            if (i == n - 2) {
                is_spare = true;
                goto END;
            } else {
                if (vks [i + 1] == 0) {
                    is_spare = true;
                    goto END;
                }
            }
        }
        if (spk [i]) {
            if (i == 0) {
                is_spare = true;
                goto END;
            } else {
                if (vks [i - 1] == 0) {
                    is_spare = true;
                    goto END;
                }
            }
        }
    }

    END:;

    int tot = is_spare;
    for (int i = 0; i < n; ++i) {
        tot += vks [i];
    }
    
    std::cout << tot;
    return 0;
}