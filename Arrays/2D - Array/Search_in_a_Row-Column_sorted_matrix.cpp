// problem: https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

/*
Approach: Using Binary Search
Time Complexity:    O(M*log N)
Space Complexity:   O(1)
*/
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++){
            int start = 0;
            int end = n-1;
            while(start <= end){
                int mid = start + (end - start)/2;
                if(mat[i][mid] == x)
                    return true;
                else if(mat[i][mid] > x)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return false;
    }
};
