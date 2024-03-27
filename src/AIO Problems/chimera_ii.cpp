#include <fstream>

int main() {
    int n;
    std::ifstream ReadFile("chimin.txt");
    std::ofstream WriteFile("chimout.txt");

    ReadFile >> n;
    std::string arr1;
    std::string arr2;
    std::string arr3;
    ReadFile >> arr1 >> arr2 >> arr3;

    bool can_do = true;
    int swaps = 0;
    std::string* cur_arr;
    for (int l = 0; l < n; ++l) {
        if (arr1 [l] == arr3 [l]) {
            if (cur_arr != &arr1 && arr2 [l] != arr3 [l]) {
                ++swaps;
                cur_arr = &arr1;
            }
        } else if (arr2 [l] == arr3 [l]) {
            if (cur_arr != &arr2) {
                ++swaps;
                cur_arr = &arr2;
            }
        } else {
            can_do = false;
            break;
        }
    }

    if (can_do) {
        WriteFile << "SUCCESS\n" << (swaps - 1);
    } else {
        WriteFile << "PLAN FOILED";
    }

    return 0;
}