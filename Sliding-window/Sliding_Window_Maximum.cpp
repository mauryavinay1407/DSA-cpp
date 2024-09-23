// problem :   https://leetcode.com/problems/sliding-window-maximum/description/

/*
Approach-1:   Brute force
Time Complexity:  O(n*k)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> slidingWindow(vector<int> v,int k)
    {
        vector <int> temp;
        for(int i=0;i<v.size()-k+1;i++)
        {
            int max=v[i];
            for(int j=i+1;j<k+i;j++)
            {
              if(max<v[j])
              max=v[j];
            }
            temp.push_back(max);
        }
        return temp;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    return slidingWindow(nums,k);
    }
};


/*
Approach-2:   using sliding window
Time Complexity:  O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // we can use dq or list i.e which have access to both end.
        deque<int> dq;
        int i=0,j=0;
        vector<int> result;
        while(j<nums.size()){
        while(!dq.empty() && nums[j]>dq.back())
        dq.pop_back();

        dq.push_back(nums[j]);
        if(j-i+1==k){
         result.push_back(dq.front());
         if(nums[i]==dq.front())
         dq.pop_front();
         i++;
        }
        j++;
        }
        return result;
    }
};
