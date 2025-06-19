// problem  : https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1

/*
Approach-1 :  Using sorting 
Time Complexity       :  O(N*logN)
Space Complexity      :  O(N)
*/

class Solution{
public:
    string caseSort(string str, int n){
        // code here
         vector<int> pos_l;
         vector<int> pos_u;
        
        for(int i=0;i<n;i++){
            if(str[i]>='a'){
            pos_l.push_back(str[i]-'a');    
            }
            else{
            pos_u.push_back(str[i]-'A');    
            }
        }
        
        sort(pos_l.begin(),pos_l.end());
        sort(pos_u.begin(),pos_u.end());
        
        string res="";
  
        int j=0,k=0;
        for(int i=0;i<str.size();i++){
            if(str[i]>='a')
            res+=('a'+pos_l[j++]);
            else
            res+=('A'+pos_u[k++]);
        }
        return res;
    }
};
/*
Approach-2 :  Optimal using frequency arrays 
Time Complexity       :  O(N)
Space Complexity      :  O(1)
*/
class Solution {
  public:
    string caseSort(string& s) {
        // code here
        vector<int> upperCase(26,0);
        vector<int> lowerCase(26,0);
        // storing the frequencies
        for(auto& ch : s){
            if((ch - 'A' >= 0 && ch - 'A' < 26)){
                upperCase[ch - 'A']++;
            }
            else{
                lowerCase[ch - 'a']++;
            }
        }
        
        string result = "";
        int i = 0;
        int j = 0;
        
        // building the result
        for(auto& ch : s){
            if(ch - 'A' >= 0 && ch - 'A' < 26){
                while(upperCase[i] == 0){
                    i++;
                }
                result += (i + 'A');
                upperCase[i]--;
            }
            else{
                while(lowerCase[j] == 0){
                    j++;
                }
                result += (j + 'a');
                lowerCase[j]--;
            }
        }
        return result;
    }
};
