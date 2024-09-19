// problem:  https://leetcode.com/problems/sudoku-solver/description

/*
Time Complexity: O(9^81) in the worst case.
Space Complexity: O(1) 
*/

class Solution {
public:
    bool isValid(vector<vector<char>>& board,int row,int col,char x){
        for(int i=0;i<9;i++){
          if(board[i][col]==x)
            return false;
        }
        for(int j=0;j<9;j++){
          if(board[row][j]==x)
            return false;
        }
        int startRow = row - row % 3;
        int startCol = col - col % 3;
           for (int i = 0; i < 3; i++) {
              for (int j = 0; j < 3; j++) {
                if (board[i + startRow][j + startCol] == x)
                   return false;
          }
       }
        return true;
    }

    bool sudokuSolver(vector<vector<char>>& board,int i,int j){
        if(i==9)
        return true;
        if(j==9)
        return sudokuSolver(board,i+1,0);
        if(board[i][j]!='.')
        return sudokuSolver(board,i,j+1);

        for(int start=1;start<=9;start++){
            if(isValid(board,i,j,start+'0')){
                board[i][j]=start+'0';
                if(sudokuSolver(board,i,j+1))
                return 1;
                board[i][j]='.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
      sudokuSolver(board,0,0);
    }
};
