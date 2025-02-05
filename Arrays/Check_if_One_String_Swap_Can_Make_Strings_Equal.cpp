// problem : https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

/*
Approach-1 :  Brute force 
Time Complexity    :   O(N)
Space Complexity   :   O(N)
*/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length() != s2.length())
            return false;
        int n = s1.length();
        vector<int> first(26,0);
        vector<int> second(26,0);
        for(int i=0;i<n;i++){
            first[s1[i]-'a']++;
            second[s2[i]-'a']++;
        }
        if(first != second)
            return false;
        vector<int> track(n,0);
        int i=0;
        while(i < n){
            if(s1[i] == s2[i])
                track[i] = 1;
            i++;
        }
        int count = 0;
        for(auto& t : track)
            if(t == 0)
                count++;
        return count <= 2;
    }
};
/*
Approach-2 :  Optimal
Time Complexity    :   O(N)
Space Complexity   :   O(1)
*/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length() != s2.length())
            return false;
        int n = s1.length();
        int first = -1,second = -1;
        int count = 0;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]){
                count++;
                if(first == -1)
                    first = i;
                else if(second == -1)
                    second = i;
            }
        }
        if(count == 0 || (count == 2 && s1[first] == s2[second] && s1[second] == s2[first]))
            return true;
        return false;
    }
};
