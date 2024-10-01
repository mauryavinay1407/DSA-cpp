// problem:  https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/

/*
Approach: using remainder 
Time Complexity: O(n)
Space Complexity: O(k)
*/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
     vector<int> mp(k,0);
     for(auto& num:arr)
     mp[((num%k)+k)%k]++;

        if(mp[0]%2!=0)
         return false;
    for(int i=1;i<=k/2;i++){
        if(mp[i]!=mp[k-i])
         return false;
    }

    return true;
    }
};
