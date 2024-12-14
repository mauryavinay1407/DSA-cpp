// problem : https://leetcode.com/problems/continuous-subarrays

/*
Approach-1: Brute force
Time Complexity:     O(N^3)
Space Complexity:    O(1)
*/
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bool isValid = true;
                for (int k1 = i; k1 <= j; k1++) {
                    for (int k2 = k1 + 1; k2 <= j; k2++) {
                        if (abs(nums[k1] - nums[k2]) > 2) {
                            isValid = false;
                            break;
                        }
                    }
                    if (!isValid)
                        break;
                }
                if (isValid)
                    result++;
            }
        }

        return result;
    }
};

/*
Approach-2: Better using Heap
Time Complexity:     O(N*logN)
Space Complexity:    O(N)
*/
class Solution {
public:
    using P = pair<int, int>
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> minHeap;
        priority_queue<P> maxHeap;
        int i = 0;
        int j = 0;
        long long count = 0;
        while(j < n) { //O(n)
            minHeap.push({nums[j], j}); //Log(n)
            maxHeap.push({nums[j], j}); //Log(n)
            while(abs(maxHeap.top().first - minHeap.top().first) > 2) {
                i++;
                while(!maxHeap.empty() && maxHeap.top().second < i) {
                    maxHeap.pop();
                }
                while(!minHeap.empty() && minHeap.top().second < i) {
                    minHeap.pop();
                }
            }
            count += j-i+1;
            j++;
        }
        //T.C: O(nlogn)
        return count;
    }
};
/*
Approach-3: Optimal using ordered map
Time Complexity:     O(N)
Space Complexity:    O(1)
*/
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long result = 0;
        int i=0;
        int j=0;
        map<int,int> mp;  // space will be O(1) because there wouldn't be more than 3 elements in map at a single time
        while(j < nums.size()){
            mp[nums[j]]++;
            while(abs(mp.rbegin()->first - mp.begin()->first) > 2){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            result += (j - i + 1);
            j++;
        }
        return result;
    }
};
