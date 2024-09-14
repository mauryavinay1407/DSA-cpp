// problem:  https://leetcode.com/problems/pascals-triangle/

/*
    rows cols:| 0 | 1 | 2 | 3 | 4 |    
      0       | 1 |   |   |   |   |
      1       | 1 | 1 |   |   |   |
      2       | 1 | 2 | 1 |   |   |
      3       | 1 | 3 | 3 | 1 |   |
      4       | 1 | 4 | 6 | 4 | 1 |
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res; 
     for(int i=0;i<numRows;i++){
        vector<int> nums(i+1,1);
        res.push_back(nums);
        for(int j=1;j<i;j++){
         res[i][j]=res[i-1][j]+res[i-1][j-1];
        }
     }
     return res;
    }
};
