#include <iostream>
#include <string>
#include <vector>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair

int main() {
    int t; std::cin >> t;
    while (t--) {
        std::string s_; std::cin >> s_;
        std::vector<int> imp_points;
        int count = 0; for (int i = 0; i < s_.length(); ++i) {
            if (s_ [i] == 48) {
                ++count;
                imp_points.push_back(i + 1);
            }
        }
        if (count == s_.length()) {
            std::cout << "0\n";
            continue;
        }
        int leads = 0; for (int i = 0; i < s_.length(); ++i) {
            if (s_ [i] == 49) break;
            ++leads;
            imp_points.erase(imp_points.begin());
        }
        unsigned long long tot = 0;
        while (leads < count) {
            tot += *imp_points.begin();
            imp_points.erase(imp_points.begin());
            tot -= leads;
            ++leads;
        }
        
        std::cout << tot << '\n';
    }

    return 0;
}