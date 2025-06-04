// problem  : https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

/*
Approach - Using recursion  + memoization
Time Complexity      :  O(|s1| × |s2| × |s3|)
Space Complexity     :  O(|s1| × |s2| × |s3|)
*/
class Solution {
public:
    int findLCS(string& s1, string& s2,string& s3,int i,int j,int k,vector<vector<vector<int>>>& dp){
        if(i >= s1.length() || j >= s2.length() || k >= s3.length()){
            return 0;
        }
        
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        
        if(s1[i] == s2[j] && s2[j] == s3[k]){
            return dp[i][j][k] = 1 + findLCS(s1,s2,s3,i + 1,j + 1,k + 1,dp);
        }
        
        return dp[i][j][k] = max({findLCS(s1,s2,s3,i + 1,j + 1,k,dp)
                           ,findLCS(s1,s2,s3,i,j,k + 1,dp)
                           ,findLCS(s1,s2,s3,i + 1,j,k,dp)
                           ,findLCS(s1,s2,s3,i,j + 1,k,dp)});

    }
    
    int lcsOf3(string& s1, string& s2, string& s3) {
        vector<vector<vector<int>>> dp(s1.length(),vector<vector<int>>(s2.length(),vector<int>(s3.length(),-1)));
        return findLCS(s1,s2,s3,0,0,0,dp);
    }
};
