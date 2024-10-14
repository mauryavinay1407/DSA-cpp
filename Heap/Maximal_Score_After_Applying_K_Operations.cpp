// problem:  https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/

/*
Approach-1: Brute force(TLE)
Time Complexity: O(n*k)
Space Complexity: O(1)
*/

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        long long maxScore = 0;

        while (k--) {
            // Find the maximum element
            auto maxIt = std::max_element(nums.begin(), nums.end());

            // Add the maximum element to the score
            maxScore += *maxIt;

            // Replace the maximum element by ceil(max / 3)
            *maxIt = std::ceil(*maxIt / 3.0);
        }

        return maxScore;
    }
};

/*
Approach-2: Using max heap
Time Complexity: O(n + klogn)
Space Complexity: O(k)
*/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(begin(nums),end(nums));
        long long maxScore=0;
        while(k--){
            int temp=pq.top();
            pq.pop();
            maxScore+=temp;
            pq.push(ceil(temp/3.0));
        }
        return maxScore;
    }
};
