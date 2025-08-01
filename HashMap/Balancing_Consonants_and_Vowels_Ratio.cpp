// problem : https://www.geeksforgeeks.org/problems/balancing-consonants-and-vowels-ratio/1

/*
Approach - Using prefix sum with hashing
Time Complexity       :  O(N)
Space Complexity      :  O(N)
*/
class Solution {
  public:
    bool isVowel(char x){
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }
    int countBalanced(vector<string>& arr) {
        // code here
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        int result = 0;
        int sum = 0;
        
        for(auto& str : arr){
            int n = str.length();
            
            for(int i = 0; i < n; i++){
                if(isVowel(str[i])){
                    sum++;
                }else{
                    sum--;
                }
                
                if(i == n - 1){
                    result += mp[sum];
                    mp[sum]++;
                }
            }
        }
        return result;
    }
};
