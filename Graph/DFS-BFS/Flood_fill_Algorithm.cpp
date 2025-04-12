// problem : https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

/*
Approach:1 (DFS)
Time Complexity: O(m*n)
Space Complexity: O(m*n) (due to recursion depth in the DFS).
*/

class Solution {
public:
  int m,n;
    vector<vector<int>> directions{{0,1},{1,0},{0,-1},{-1,0}};
    bool isValid(int i,int j){
        return i >= 0 && i < m && j >= 0 && j < n ;
    }
    
    void dfs(vector<vector<int>>& img,int i,int j,int newColor,int oldColor){
        if(i < 0 || i >= m || j < 0 || j >= n || img[i][j] != oldColor){
            return ;
        }
        img[i][j] = newColor;
        for(auto& dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(isValid(new_i,new_j) && img[new_i][new_j] == oldColor){
                dfs(img,new_i,new_j,newColor,oldColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        m = image.size();
        n = image[0].size();
        int oldColor = image[sr][sc];
        if(oldColor != newColor) {
            dfs(image, sr, sc, newColor, oldColor);
        }
        return image;
    }
};
