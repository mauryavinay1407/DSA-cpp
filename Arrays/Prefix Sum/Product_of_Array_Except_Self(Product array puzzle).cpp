// leetcode :  https://leetcode.com/problems/product-of-array-except-self
// gfg      :  https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1

/*
Approach-1 : extra space using 2 pass
Time Complexity      :  O(N)
Space Complexity     :  O(N)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        vector<int> leftProduct(nums.size(), 1);
        vector<int> rightProduct(nums.size(), 1);
        // For calculating product of left side of each index
        for (int i = 1; i < nums.size(); i++)
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
        // For calculating product of right side of each index
        for (int i = nums.size() - 2; i >= 0; i--)
            rightProduct[i] = rightProduct[i + 1] * nums[i + 1];

        // Calculating the complete product by multiplying left and right
        for (int i = 0; i < nums.size(); i++)
            ans.push_back(leftProduct[i] * rightProduct[i]);

        return ans;
    }
};
/*
Approach-2 : without extra space but a little messy
Time Complexity      :  O(N)
Space Complexity     :  O(1)
*/

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        long long product = 1;
        vector<int> result;
        int isZero = 0;
        for(auto& num : arr){
            if(num)
                product *= num;
            else
                isZero++;
        }
        // if more than one 0 is there
        if(isZero > 1){
            result.assign(arr.size(),0);
            return result;
        }
        // if one 0 is there
        if(isZero){
            for(auto& num : arr){
                if(num)
                    result.push_back(0);
                else
                    result.push_back(product);
            }
            return result;
        }
        // if not 0 is there
        for(auto& num : arr){
                result.push_back(product/num);
        }
        return result;
    }
};
/*
Approach-3 : without extra space clean using prefix product
Time Complexity      :  O(N)
Space Complexity     :  O(1)
*/

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n,1);
        // calculate prefix products
        int prefix = 1;
        for(int i=0;i<n;i++){
            result[i] = prefix;
            prefix *= arr[i];
        }
        
        // calculate suffix products
        int suffix = 1;
        for(int i=n-1;i>=0;i--){
            result[i] *= suffix;
            suffix *= arr[i];
        }
        
        return result;
    }
};
