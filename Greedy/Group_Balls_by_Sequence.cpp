// problem  :  https://www.geeksforgeeks.org/problems/group-balls-by-sequence/1

/*
Approach - Using Greedy + Map
Time Complexity       :  O(N*logN)
Space Complexity      :  O(N)
*/
class Solution {
public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        if(arr.size() % k != 0){
            return false;
        }
        map<int,int> mp;
        // store the frequencies
        for(auto& num : arr){
            mp[num]++;
        }
        
        // checking for group existence
        for(auto& m: mp){
            int num = m.first;
            int count = m.second;
            
            if(count > 0){
                for(int i = 0; i < k; i++){
                    if(mp[num + i] < count){
                        return false;
                    }
                    mp[num + i] -= count;
                }
            }
        }
        
        return true;
    }
};
