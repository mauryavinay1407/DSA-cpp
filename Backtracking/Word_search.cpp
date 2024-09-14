// problem:  https://leetcode.com/problems/word-search/description/

/*Space Complexity: O(L)
Time Complexity: O(M * N * 3^L)  (where L=word length)
Space Complexity is because of recursion - to store function stack context.
Time Complexity - from every block we go in three adjacent blocks (avoiding the direction we came from). 
This walk can go for max of L times. So each thred at most goes L length long. -> O(3^L).
Now this is applied at each node from main calling function -> O(M * N). Therefore, O(M * N * 3^L).
*/

class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool isExist(vector<vector<char>>& board,int index,int i,int j,string word){
        if(index>=word.length())
        return true;

        if(i<0||j<0||i>=rows||j>=cols||board[i][j]=='$')
        return false;

        if(board[i][j]!=word[index])
        return false;

        char temp=board[i][j];
        board[i][j]='$';

        for(auto& dir:directions){
         int new_i=i+dir[0];
         int new_j=j+dir[1];

        if(isExist(board,index+1,new_i,new_j,word))
        return true;
        }
        board[i][j]=temp;
       return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int index=0;
        rows=board.size();
        cols=board[0].size();
        if(rows*cols<word.size())
        return false;

     for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(board[i][j]==word[index] && isExist(board,index,i,j,word))
            return true;
        }
     }
     return false;
    }
};
