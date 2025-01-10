// problem : https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

/*
Approach- Using hashmaps
Time Complexity   :  O(N)
Space Complexity  :  O(k)
*/
class Solution {
public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        vector<int> result;
        while(j < arr.size()){
            mp[arr[j]]++;
            if(j - i + 1 == k){
                result.push_back(mp.size());
                mp[arr[i]]--;
                if(mp[arr[i]] == 0)
                    mp.erase(arr[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};
