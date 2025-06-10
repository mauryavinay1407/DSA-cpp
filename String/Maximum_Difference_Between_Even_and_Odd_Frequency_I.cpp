// problem  :  https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i

/*
Approach - Counting the frequency
Time Complexity       :  O(N)
Space Complexity      :  O(1)
*/
class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);

        for (auto& w : s) {
            freq[w - 'a']++;
        }
        int oddMax = 0;
        int evenMin = s.length();

        for (auto& f : freq) {
            if (f % 2 == 0 && f > 0) {
                evenMin = min(evenMin, f);
            } else {
                oddMax = max(oddMax, f);
            }
        }
        return oddMax - evenMin;
    }
};
