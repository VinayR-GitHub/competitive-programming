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
    FILE(baubles);
    int ro, bo, s, rp, bp, cost; std::cin >> ro >> bo >> s >> rp >> bp;
    
    if (bp == 0) {
        std::cout << MAX(0, ro - rp + s + 1);
        return 0;
    }
    if (rp == 0) {
        std::cout << MAX(0, bo - bp + s + 1);
        return 0;
    }

    int b_, r_, c_; b_ = s + bo - bp; r_ = s + ro - rp; c_ = s + bo + ro - bp - rp;
    if (b_ < 0 || r_ < 0 || c_ < 0) {
        std::cout << 0;
        return 0;
    }
 
    std::cout << MAX(0, MIN(b_, MIN(r_, c_)) + 1);
    
    return 0;
}