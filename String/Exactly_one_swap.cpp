//  problem  :  https://www.geeksforgeeks.org/problems/exactly-one-swap--170637/1

/*
Approach - By substracting duplicates from all occurence
Time Complexity       :  O(N)
Space Complexity      :  O(1)
*/
class Solution {
public:
    int countStrings(string &s) {
        
        int n = s.length();
        // finding possible swaps for 2 distinct position from n
        int totalSwaps = n * (n - 1) / 2;

        int count = 0;
        vector<int> freq(26,0);
        // counting the frequency of letters
        for(auto& w : s){
            if(freq[w - 'a'] == 0){
                count++;
            }
            freq[w - 'a']++;
        }
        
        // return if occurence all letters are distinct
        if(count == n){
            return totalSwaps;
        }
        
        int duplicateSwaps = 0;
        // removing the duplicate letters
        for(auto& f : freq){
            if(f > 1){
                duplicateSwaps += f * (f - 1) / 2;
            }
        }
        
        totalSwaps -= duplicateSwaps;
        
        // adding the removed occurence
        return totalSwaps + 1;
    }
};
