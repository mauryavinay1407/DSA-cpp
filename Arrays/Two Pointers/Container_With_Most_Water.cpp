// problem: https://leetcode.com/problems/container-with-most-water/description/

/*
Approach-1:  brute force
Time Complexity: O(N^2)
Space Complexity: O(N)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);   // Array to store the maximum heights from the left
        vector<int> rightMax(n);  // Array to store the maximum heights from the right

        // Fill the leftMax array
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Fill the rightMax array
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int maxArea = 0;

        // calculate the area for each pair of indices
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // find the minimum height between leftMax and rightMax for the indices
                int minHeight = min(leftMax[i], rightMax[j]);
                // find the area between indices i and j
                int currentArea = (j - i) * minHeight;
                // Update the maximum area
                maxArea = max(maxArea, currentArea);
            }
        }

        return maxArea;
    }
};


/*
Approach-2: a little optimize
Time Complexity: O(N^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;  
        for(int i = 0; i < height.size(); i++) {
            for(int j = i + 1; j < height.size(); j++) {
                int current_area = (j - i) * min(height[i], height[j]);
                ans = max(ans, current_area);
            }
        }
        
        return ans;
    }
};


/*
Approach-3:  using two pointers
Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
       int left=0;
       int right=height.size()-1;
       int ans=INT_MIN;
       while(left<right){
       ans=max(ans,(right-left)*min(height[left],height[right]));
       (height[left]>height[right]) ? right-- : left++;
       }
       return ans;
    }
};
