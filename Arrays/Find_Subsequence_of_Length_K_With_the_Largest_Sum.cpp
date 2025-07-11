// problem   :   https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum

/*
Approach-1 : Brute Force using recursion(TLE)
Time Complexity     :  O(2^N)
Space Complexity    :  O(1)
*/
class Solution {
public:
    vector<int> result;
    void findMax(vector<int>& nums, int i, int k, int sum, int& maxi,
                 vector<int>& temp) {
        if (k == 0) {
            if (sum > maxi) {
                maxi = sum;
                result = temp;
            }
            return;
        }
        if (i >= nums.size())
            return;

        temp.push_back(nums[i]);
        findMax(nums, i + 1, k - 1, sum + nums[i], maxi, temp);
        temp.pop_back();

        findMax(nums, i + 1, k, sum, maxi, temp);
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp;
        int maxi = INT_MIN;
        findMax(nums, 0, k, 0, maxi, temp);

        return result;
    }
};
/*
Approach-2 :  Slight better using map
Time Complexity     :  O(N*k)
Space Complexity    :  O(k)
*/
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        map<int,int> mp;
        while(k){
            auto it = max_element(nums.begin(),nums.end());
            int maxi = *it;
            int pos = it - nums.begin();
            mp[pos] = maxi;
            nums[pos] = INT_MIN;
            k--;
        }
        vector<int> result;
        for(auto& m : mp){
            result.push_back(m.second);
        }

        return result;
    }
};
/*
Approach-3 :  more better using sorting
Time Complexity     :  O(N*logN)
Space Complexity    :  O(1)
*/
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n)
            return nums;

        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = make_pair(i, nums[i]);
        }

        auto lambda = [](auto &p1, auto& p2) {
            return p1.second > p2.second;
        };

        sort(begin(vec), end(vec), lambda);

        sort(begin(vec), begin(vec)+k);

        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(vec[i].second);
        }

        return result;
    }
};

/*
Approach-4 : optimal using nth_element function c++
Time Complexity     :  O(n + k)
Space Complexity    :  O(n)
*/
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if (nums.size() == k)
            return nums;

        vector<int> temp = nums;

        // Use nth_element to put the k largest elements in the first k positions (unordered)
        nth_element(temp.begin(), temp.begin() + (k - 1), temp.end(),greater<int>());

        // Count how many times kth largest appears in top k elements
        int countLimit = count(temp.begin(), temp.begin() + k, temp[k - 1]);

        vector<int> result;
        int limit = temp[k - 1];

        for (int i = 0; i < nums.size(); i++) {
            if (limit < nums[i]) {
                result.push_back(nums[i]);
            } else if (limit == nums[i]) {
                if (countLimit) {
                    result.push_back(nums[i]);
                    countLimit--;
                }
            }
            if (result.size() == k)
                break;
        }
        return result;
    }
};
