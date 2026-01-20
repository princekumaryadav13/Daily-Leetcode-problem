class Solution {
public:
    int row, col;
    vector<vector<bool>> visited;
   bool check(vector<vector<char>>& board, string word,int i,int j,int r){
      if(r==word.size()) return true;

      if(i<0 ||j<0||i >= row || j >= col|| board[i][j] != word[r] || visited[i][j] ) return false;

       visited[i][j] = true;
               bool res= check(board, word, i+1, j, r+1) ||
                   check(board, word, i-1, j, r+1) ||
                   check(board, word, i, j+1, r+1) ||
                   check(board, word, i, j-1, r+1);

                   visited[i][j]=false;

                    visited[i][j] = false; // backtrack
        return res;
   }
    bool exist(vector<vector<char>>& board, string word) {
         row = board.size();
        col = board[0].size();

       visited = vector<vector<bool>>(row,vector<bool>(col,false));

        for(int i=0;i<row;i++){
          for(int j=0;j<col;j++){
            if(check( board, word,i,j,0)) return true;
          }
        
        }
        return false;
    }
};