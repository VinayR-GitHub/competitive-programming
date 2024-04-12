#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

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
    FILE(hire);
    int n; std::cin >> n; int temp_val; int num = 0;
    std::deque<int> skills; for (int i = 0; i < n; ++i) std::cin >> temp_val, skills.push_back(temp_val);
    int students; std::cin >> students;
    std::deque<int> studskills; for (int i = 0; i < students; ++i) std::cin >> temp_val, studskills.push_back(temp_val);
    int masters; std::cin >> masters;
    std::deque<int> mastskills; for (int i = 0; i < masters; ++i) std::cin >> temp_val, mastskills.push_back(temp_val);
    std::sort(skills.begin(), skills.end()); std::sort(studskills.begin(), studskills.end()); std::sort(mastskills.begin(), mastskills.end(), std::greater<int>());

    while (true) {
        if (!studskills.size() || !skills.size()) {
            break;
        }
        if (skills.front() <= studskills.front()) {
            ++num;
            skills.pop_front(); studskills.pop_front();
        } else {
            studskills.pop_front();
        }
    }
    while (true) {
        if (!mastskills.size() || !skills.size()) {
            break;
        }
        if (skills.back() >= mastskills.front()) {
            ++num;
            skills.pop_back(); mastskills.pop_front();
        } else {
            mastskills.pop_front();
        }
    }

    std::cout << num;

    return 0;
}