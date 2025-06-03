// problem   :  https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

/*
Approach - By Subtracting At most k - 1 distinct characters from At most k distinct characters
Time Complexity        :  O(N)
Space Complexity       :  O(1)
*/
class Solution {
public:
    int countAtmostK(string& s, int k){
        int i = 0;
        int result = 0;
        
        vector<int> freq(26,0);
        int count = 0;
        for(int j = 0; j < s.length(); j++){
            freq[s[j] - 'a']++;
            if(freq[s[j]- 'a'] == 1){
                count++;
            }
            
            while(count > k){
                freq[s[i] - 'a']--;
                if(freq[s[i] - 'a'] == 0){
                    count--;
                }
                i++;
            }
            
            result += j - i + 1;
        }
        return result;
    }

    int countSubstr(string& s, int k) {
        return countAtmostK(s, k) - countAtmostK(s, k - 1);
    }
};
