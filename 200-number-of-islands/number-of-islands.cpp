class Solution {
public:
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    void check(vector<vector<char>>& grid,int i,int j){

        queue<pair<int,int>>pq;
        grid[i][j]='0';
        pq.push({i,j});

        while(!pq.empty()){
            auto [x,y] = pq.front();
            pq.pop();

           for(int i=0;i<4;i++){
            int ni = x+dir[i][0];
            int nj = y+dir[i][1];

            if(ni>=0 && nj>=0 && ni<grid.size() && nj < grid[0].size() && grid[ni][nj]=='1'){
                pq.push({ni,nj});
                grid[ni][nj]='0';
            }
           } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int island = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
              if(grid[i][j]=='1'){
                check(grid,i,j);
                island++;
              }
            }
        }
        return island;
    }
};