// problem  :  https://leetcode.com/problems/candy

/*
Approach-1 : Using 2 passes , from left to right and then right to left
Time Complexity      :  O(N)
Space Complexity     :  O(N)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1) {
            return 1;
        }
        vector<int> candy(n, 1);

        for (int i = 0,j = 1; j < n; j++, i++) {
            if (ratings[i] < ratings[j]) {
                candy[j] = max(candy[j],candy[i] + 1);
            }
        }
        for (int i = n - 2,j = n - 1; i >= 0; j--, i--) {
            if (ratings[i] > ratings[j]) {
                candy[i] = max(candy[i],candy[j] + 1);
            }
        }
        return accumulate(candy.begin(), candy.end(), 0);
    }
};

/*
Approach-2:  Using 1 pass by considering the monotonicity
Time Complexity      :  O(N)
Space Complexity     :  O(1)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int candies = n;
        while (i < n) {
            // if ratings are same
            if (ratings[i - 1] == ratings[i]) {
                i++;
                continue;
            }
            // increasing ratings
            int peak = 0;
            while (ratings[i - 1] < ratings[i]) {
                peak++;
                candies += peak;
                i++;
                if (i == n) {
                    return candies;
                }
            }
            // decreasing ratings
            int dip = 0;
            while (i < n && ratings[i - 1] > ratings[i]) {
                dip++;
                candies += dip;
                i++;
            }
            candies -= min(peak, dip);
        }
        return candies;
    }
};
