class Solution {
public:
    int count =0;
    int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

     void check(vector<vector<char>>& grid , int i ,int j){
        
        
        grid[i][j]='0';
        for(auto dir : dirs){
            int ni =i+ dir[0];
            int nj =j+ dir[1];
            if(ni>=0 && nj>=0 && ni<grid.size()&& nj<grid[0].size() && grid[ni][nj]=='1'){

                check(grid , ni , nj); 

            }
        }
        return ;
     }
    int numIslands(vector<vector<char>>& grid) {
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    check(grid, i,j);
                    count++;
                }
            }
        }
        return count;
    }
};