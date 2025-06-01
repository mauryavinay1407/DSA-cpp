//  problem  :  https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1

/*
Approach - Using Binary Search
Time Complexity      :  O(N^2)
Space Complexity     :  O(1)
*/
class Solution {
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        int n = mat1.size();
        int p1 = 0;
        int p2 = n*n - 1;
        int result = 0;
        
        while(p1 < n*n  && p2 >= 0){
            int i1 = p1 / n , j1 = p1 % n;
            int i2 = p2 / n , j2 = p2 % n;
            
            int sum = mat1[i1][j1] + mat2[i2][j2];
            
            if(sum == x){
                result++;
                p1++;
                p2--;
            }
            else if(sum < x){
                p1++;
            }
            else{
                p2--;
            }
        }
        return result;
    }
};
