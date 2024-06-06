#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

int main() {
    FILE(pairs);
    int n, a, b; std::cin >> n >> a >> b; int si;
    std::vector<int> skill; for (int i = 0; i < n; ++i) std::cin >> si, skill.push_back(si);
    std::sort(skill.begin(), skill.end());

    long long count = 0;
    for (auto& student : skill) {
        a -= student; b -= student;
        auto lower = lower_bound(skill.begin(), skill.end(), a);
        auto upper = upper_bound(skill.begin(), skill.end(), b);
        count += (upper - lower);
        a += student; b += student;
        if (2 * student >= a && 2 * student <= b) --count;
    }

    std::cout << count / 2;

    return 0;
}