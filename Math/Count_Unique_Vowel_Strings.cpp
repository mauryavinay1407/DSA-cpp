// problem : https://www.geeksforgeeks.org/problems/count-unique-vowel-strings/1

/*
Approach - Using hash map frequency counting.
Time Complexity       :   O(N)
Space Complexity      :   O(1)
*/
class Solution {
public:
    int vowelCount(string& s) {
        unordered_map<char,int> mp;
      // store the frequency of the vowels
        for(auto& w : s){
            if(w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u'){
                mp[w]++;
            }
        }
        int k = mp.size();
      // check whether no vowel is present
        if(k == 0){
            return 0;
        }
        int result = 1;
      // multiplying the possibility of every vowel along with their frequency
        for(auto& m : mp){
            result *= (k * m.second);
            k--;
        }
        return result;
    }
};
