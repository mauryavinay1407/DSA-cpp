// problem : https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1


/*
Approach - Using unordered set for linear search of words
Time Complexity    :  O(n * max(words[i].size()) )
Space Complexity   :  O(n * max(words[i].size()) )
*/
class Solution {
public:
    string longestString(vector<string> &words) {
        // code here
        unordered_set<string> st(words.begin(),words.end());
        string result = "";
        for(auto& str : words){
            string temp = "";
            bool flag = true;
            for(int i = 0; i < str.length(); i++){
                temp += str[i];
                if(!st.count(temp)){
                    flag = false;
                    break;
                } 
            }
            if(flag){
                if(temp.length() > result.length()){
                    result = temp;
                }else if(temp.length() == result.length()){
                    result = min(result,temp);
                }
            }
        }
        return result;
    }
};
