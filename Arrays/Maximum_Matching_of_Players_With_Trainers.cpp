// problem : https://leetcode.com/problems/maximum-matching-of-players-with-trainers

/*
Approach - Using sorting + greedy
Time Complexity      :   O(nlogn + mlogm + min(m, n)), where m = size of players and n = size of trainers
Space Complexity     :   O(1)
*/
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0;
        int result = 0;
        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                result++;
                i++;
            }
            j++;
        }
        return result;
    }
};
