// problem  :  https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes

/*
Approach - Calculating MD at every point greedily
Time Complexity     :  O(N)
Space Complexity    :  O(N)
*/
class Solution {
public:
    int calculateDist(int N, int S, int W, int E) {
        return abs(N - S) + abs(W - E);
    }

    int maxDistance(string s, int k) {
        unordered_map<char, int> mp{{'N', 0}, {'S', 0}, {'W', 0}, {'E', 0}};

        int maxMD = 0;
        for (int i = 0; i < s.length(); i++) {
          // storing frequency
            mp[s[i]]++;
        // calculationg Manhatten Distance
            int currentMD = calculateDist(mp['N'], mp['S'], mp['W'], mp['E']);
            int stepsTillNow = i + 1;
            int wasted = stepsTillNow - currentMD;

            int extra = 0;
          // calc.. wasted steps
            if (wasted) {
                extra = min(2 * k, wasted);
            }

            maxMD = max(maxMD, currentMD + extra);
        }
        return maxMD;
    }
};
