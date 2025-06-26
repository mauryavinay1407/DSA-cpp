// problem  :  https://www.geeksforgeeks.org/problems/check-frequencies4211/1

/*
Approach - Using hash set
Time Complexity      :  O(N)
Space Complexity     :  O(1)
*/
class Solution {
public:
    bool sameFreq(string& s) {

        vector<int> freq(26,0);
        
        for(auto& ch : s){
            freq[ch - 'a']++;
        }
        
        unordered_map<int,int> freqCount;
        for(auto& f : freq){
            if(f){
                freqCount[f]++;
            }
        }
        
        if(freqCount.size() > 2) return false;
        
        if(freqCount.size() == 1) return true;
        
        auto it = freqCount.begin();
        int f1 = it->first , c1 = it->second;
        ++it;
        int f2 = it->first, c2 = it->second;
        
        if((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)){
            return true;
        }
        
        if (abs(f1 - f2) == 1) {
            if ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)) return true;
        }
        
        return false;
    }
};
