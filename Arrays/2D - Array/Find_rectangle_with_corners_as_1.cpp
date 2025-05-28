// problem  :  https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1

/*
Approach - Using loops
Time Complexity         :  O(N^2*M)
Space Complexity        :  O(1)
*/
class Solution {
public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int cnt = 0;
                for(int k=0;k<m;k++){
                    if(mat[i][k]+mat[j][k]==2)cnt++;
                }
                
                if(cnt>=2) return true;
            }
        }
        return false;
    }
};



