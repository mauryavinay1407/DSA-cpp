// problem : https://leetcode.com/problems/find-champion-ii

/*
Approach: Simple 
*/
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> temp(n, 0);
      // store the indegree of every node
        for (auto& row : edges) {
            temp[row[1]]++;
        }
        int mini = INT_MAX;
        int result = -1;
      // finding the stronger team 
        for (int i = 0; i < n; i++){
            if(mini > temp[i]){
                mini = temp[i];
                result = i;
            }
        }
        int c = 0;
      // finding the unique stronger team
        for (int i = 0; i < n; i++)
            if (mini == temp[i])
                c++;
        return c == 1 ? result : -1;
    }
};
