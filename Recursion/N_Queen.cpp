// problem: https://leetcode.com/problems/n-queens/

/*
T.C : O(N!) 
S.C : O(N) 
*/

class Solution {
public:
    int N;
    vector<vector<string>> ans;

    bool isValid(vector<string>& boards,int cols,int rows){
     for(int i=rows-1;i>=0;i--){
        if(boards[i][cols]!='.')
        return false;
     }
     int i=rows-1,j=cols+1;
     while(i>=0 && j<N){
        if(boards[i][j]!='.')
        return false;
        i--;
        j++;
     }
     i=rows-1;
     j=cols-1;
     while(i>=0 && j>=0){
         if(boards[i][j]!='.')
        return false;
        i--;
        j--;
     }
     return true;
    }

    void solveTheNQueens(vector<string>& boards,int idx){
        if(idx>=N){
        ans.push_back(boards);
        return;
        }
        
    for(int i=0;i<N;i++){
    if(isValid(boards,i,idx)){
    boards[idx][i]='Q';
    solveTheNQueens(boards,idx+1);
     boards[idx][i]='.';
    }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        N=n;
    vector<string> boards(n,string(n,'.'));
    solveTheNQueens(boards,0);
    return ans;
    }
};
