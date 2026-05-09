class Solution {
public:
    vector<vector<int>>dirs={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    void gameOfLife(vector<vector<int>>& board) {

       int m = board.size();
       int n= board[0].size();
       vector<vector<int>>ans(m,vector<int>(n,0));

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int count =0;
            if(board[i][j]== 1){
                
               for(auto dir : dirs){
                 int ni =i+ dir[0];
                 int nj =j+ dir[1];
                 if(ni>=0 && nj>=0 && ni<m && nj <n && board[ni][nj]== 1){
                    count++;
                 }
               }
              if(count  == 2 || count == 3){
                ans[i][j]=1;
               }
             
               
            }
            else{
                 
               for(auto dir : dirs){
                 int ni =i+ dir[0];
                 int nj =j+ dir[1];
                 if(ni>=0 && nj>=0 && ni<m && nj <n && board[ni][nj]==1){
                    count++;
                 }
               }
               if(count==3){
                ans[i][j]=1;
               }
              
            }
        }
       } 
       board = ans;
    }
};