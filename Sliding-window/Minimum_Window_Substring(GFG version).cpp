// problem:  https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1


class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
      if(s.length()<p.length())
      return "-1";
      
      vector<int> mp(256,0);
      for(long long i=0;i<p.length();i++)
        mp[p[i]]++;
      
      int i=0,j=0;
      int count=0;
      int minLen=INT_MAX;
      int start_index=-1;
      
      while(j<s.length()){
            if(mp[s[j]]>0)
            count++;
            
            mp[s[j]]--;
          
         while(count==p.length()){
          if(minLen > j-i+1){
              minLen=j-i+1;
              start_index=i;
          }
              mp[s[i]]++;
              if(mp[s[i]]>0)
              count--;
           i++;
         }
         j++;
      }
      return minLen==INT_MAX ? "-1" : s.substr(start_index,minLen);
    }
};
