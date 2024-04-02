#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <deque>
#include <climits>
#include <algorithm>

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

int main() {
    unsigned long long cost = ULLONG_MAX;

    std::set<std::pair<int, int>> non_cand1_ordered_set; // First = candidate votes, second = candidate number.
    std::set<std::pair<int, int>> good_deals, bad_deals; // First = bribe price, second = iterator value.
    int n, m;
    FILE(deal);
    
    std::cin >> n >> m;

    auto prefs = new int[m]{};
    auto votes_per_cand = new int[n]{};
    auto bribes_per_cand = new std::deque<std::pair<int, int>>[n]{};

    // Votes.
    INT_FOR(i, 0, m) {
        std::cin >> prefs [i];
        ++votes_per_cand [prefs [i] - 1];
    }
    INT_FOR(j, 1, n) {
        non_cand1_ordered_set.insert(PAIR(votes_per_cand [j], j + 1));
    }

    // Bribes.
    std::vector<std::pair<int, std::pair<int, int>>> bribe_pairs;
    INT_FOR(i, 0, m) {
        int bribe;
        std::cin >> bribe;
        if (prefs [i] != 1) {
            bad_deals.insert(PAIR(bribe, i));
            bribe_pairs.push_back(PAIR(bribe, PAIR(prefs [i], i)));
        }
    }
    std::sort(bribe_pairs.begin(), bribe_pairs.end());

    for (auto& item : bribe_pairs) {
        bribes_per_cand [item.second.first - 1].push_back(PAIR(item.first, item.second.second));
    }
    int the_privileged_voters = votes_per_cand [0];

    unsigned long long pie = 0;
    // Set up a loop for different max_cand_vote_vals.
    DOWN_INT_FOR(max, m - 1, -1) {
        while (non_cand1_ordered_set.rbegin()->first > max) {
            // Add money used to bring the candidate votes down to max.
            std::pair<int, int> taktak = *non_cand1_ordered_set.rbegin();
            pie += bribes_per_cand [taktak.second - 1].front().first;
            ++the_privileged_voters;
            if (bad_deals.find(bribes_per_cand [taktak.second - 1].front()) != bad_deals.end()) {
                bad_deals.erase(bribes_per_cand [taktak.second - 1].front());
            } else if (good_deals.find(bribes_per_cand [taktak.second - 1].front()) != good_deals.end()) {
                pie -= bribes_per_cand [taktak.second - 1].front().first;
                good_deals.erase(bribes_per_cand [taktak.second - 1].front());
            }
            bribes_per_cand [taktak.second - 1].pop_front();
            non_cand1_ordered_set.erase(--(non_cand1_ordered_set.rbegin().base()));
            non_cand1_ordered_set.insert(PAIR(taktak.first - 1, taktak.second));
        }

        // Add money used to bring candidate 1 up to max.
        int how_many_votes = MAX(max - the_privileged_voters + 1, 0);
        while (good_deals.size() < how_many_votes) {
            std::pair<int, int> the_first_loser = *bad_deals.begin();
            bad_deals.erase(bad_deals.begin());
            good_deals.insert(the_first_loser);
            pie += the_first_loser.first;
        }
        while (good_deals.size() > how_many_votes) {
            std::pair<int, int> the_last_winner = *good_deals.rbegin();
            good_deals.erase(--(good_deals.rbegin().base()));
            bad_deals.insert(the_last_winner);
            pie -= the_last_winner.first;
        }

        cost = MIN(cost, pie);
    }

    std::cout << cost;

    return 0;
}