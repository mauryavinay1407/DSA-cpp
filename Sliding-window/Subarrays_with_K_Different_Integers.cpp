// problem : https://leetcode.com/problems/subarrays-with-k-different-integers/

/*
Approach-1:  Brute Force
Time Complexity: O(n^2)
Space Complexity: O(k)   where k = is the maximum number of distinct elements   
*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      int count=0;
      for(int i=0;i<nums.size();i++){
        unordered_map<int,int> mp;
        for(int j=i;j<nums.size();j++){
         mp[nums[j]]++;
         if(mp.size()==k)
         count++;
        }
      }
      return count++;
    }
};


/*
Approach-2:  using sliding window (Optimal)

    for finding exactly k diff integer,we can say:
    atleast(k)=atleast(k)+atleast(k+1)+atleast(k+2)
    atleast(k+1)=atleast(k+1)+atleast(k+2)

    exact(k) = atleast(k) - atleast(k+1)

for example:

    atleast(2)=atleast(2)+atleast(3)+atleast(4)
    atleast(3)=atleast(3)+atleast(3)

    exact(2) = atleast(2) - atleast(3)
*/  

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int countAtleastK = 0;
        unordered_map<int, int> mp;
        // calculating for atleast k diff integer
        while (j < nums.size()) {
            mp[nums[j]]++;
            while (mp.size() >= k) {
                countAtleastK += (nums.size() - j);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        i = 0, j = 0;
        int countAtleastK_plus_one = 0;
        mp.clear();
        // calculating for atleast k+1 diff integer
        while (j < nums.size()) {
            mp[nums[j]]++;
            while (mp.size() >= k + 1) {
                countAtleastK_plus_one += (nums.size() - j);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        int exact_k = countAtleastK - countAtleastK_plus_one;

        return exact_k;
    }
};

