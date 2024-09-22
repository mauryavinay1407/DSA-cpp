// problem:  https://leetcode.com/problems/minimum-window-substring/description/

/*
Approach-1 Brute Force
Time Complexity: O(n^3 * m)
Space Complexity: O(n)
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length())
          return "";
        string result="";
        int minLen=INT_MAX;
      for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
            string str=s.substr(i,j-i+1);
            int start=0;
            bool flag=false;
            while(start<t.length()){
             int index=str.find(t[start]);
             if(index != string::npos){
             str[index]='$';
             start++;
             }
             else{
             flag=true;
             break;
             }
            }
          if(!flag && (result.size()==0 || result.size()>str.size())){
              result=s.substr(i,j-i+1);
          }
        }
      }
      return result;
    }
};


/*
Approach-2 Using Sliding window
Time Complexity: O(m+n) where m = length of s and n = length of t
Space Complexity: O(n)
*/

class Solution {
public:
    string minWindow(string s, string t) {
     unordered_map<char,int> mp;
    
    for(int i=0;i<t.length();i++)
     mp[t[i]]++;
    
    int i=0,j=0;
    int start_index=0,minLen=INT_MAX;
    int count=t.size();

     while(j<s.length()){
        if(mp[s[j]]>0)
         count--;  
        mp[s[j]]--;
        while(count==0){
            if(j-i+1 < minLen){
                minLen=j-i+1;
                start_index=i;
            }
            if(mp.count(s[i])){
                mp[s[i]]++;
                if(mp[s[i]]>0)
                count++;
            }
         i++;
        }
        j++;
     }
     return minLen==INT_MAX ? "" : s.substr(start_index,minLen);
    }
};
