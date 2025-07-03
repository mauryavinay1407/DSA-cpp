// problem : https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

/*
Approach - Using unordered map + Sliding window
Time Complexity      :  O(N)
Space Complexity     :  O(1)
*/
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int,int> mp;
        
        int result = 0;
        int j = 0;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
            
            if(mp.size() <= 2){
                result = max(result, i - j + 1);
            }
            
            while(mp.size() > 2){
                mp[arr[j]]--;
                if(mp[arr[j]] == 0){
                    mp.erase(arr[j]);
                }
                j++;
            }
        }
        return result;
    }
};
