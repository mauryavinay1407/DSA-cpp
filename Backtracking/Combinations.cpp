// problem:  https://leetcode.com/problems/combinations/description/

/*
Time Complexity:O(C(n,k)⋅k)   
Space Complexity: O(C(n,k)⋅k+k)
 where C is combination
*/

class Solution {
public:
    vector<vector<int>> ans;
    void findCombinations(int& n,int& k,int i,vector<int>& temp){
      if(i>n){
       if(temp.size()==k)
       ans.push_back(temp);
       return;
      }
      if(temp.size()==k){
        ans.push_back(temp);
        return;
      }
    for(int j=i;j<=n;j++){
     temp.push_back(j);
     findCombinations(n,k,j+1,temp);
     temp.pop_back();
    }
}

    vector<vector<int>> combine(int n, int k) {
      vector<int> temp;
      findCombinations(n,k,1,temp);
      return ans;
    }
};
