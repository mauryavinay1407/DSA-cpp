// problem  : https://www.geeksforgeeks.org/problems/print-anagrams-together/1

/*
Approach: Using ordered map and storing the frequency of each character in every string
Time Complexity    :  O(n * L + n log n)
Space Complexity   :  O(n)
*/

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        map<vector<int>,vector<string>> mp;
        for(auto& str : arr){
            vector<int> freq(26,0);
            for(auto& s : str){
                freq[s-'a']++;
            }
            mp[freq].push_back(str);
        }
        vector<vector<string>> result;
        for(auto& m : mp){
            result.push_back(m.second);
        }
        return result;

    }
};
