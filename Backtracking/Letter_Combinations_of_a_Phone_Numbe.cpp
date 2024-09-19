// problem:  https://leetcode.com/problems/letter-combinations-of-a-phone-number

/*
Time complexity: O(m^n)
Space complexity: O(n^m*n)
where:  n: length of the input string
        m: average number of letters each digit can map to.
*/

class Solution {
public:
    vector<string> ans;
    void findCombination(string digits,int i,unordered_map<char,string>& mp,string& str){
      if(i>=digits.length()){
        ans.push_back(str);
        return;
      }
     for(auto& m:mp[digits[i]]){
        str+=m;
        findCombination(digits,i+1,mp,str);
        str.pop_back();
     }

    }

    vector<string> letterCombinations(string digits) {
    if(digits=="")
    return {};
    unordered_map<char,string> mp{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    string str="";
    findCombination(digits,0,mp,str);
    return ans;
    }
};
