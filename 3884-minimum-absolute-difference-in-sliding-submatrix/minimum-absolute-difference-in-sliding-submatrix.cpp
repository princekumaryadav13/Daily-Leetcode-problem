class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m= grid.size();
        int n= grid[0].size();

        vector<vector<int>>ans(m-k+1,vector<int>(n-k+1,0));

        for(int i= 0;i <= m-k;i++){
         for(int j=0;j <= n-k;j++){
            set<int>ss;
            for(int r=i;r <= i+k-1;r++){
                for(int c=j;c <= j+k-1;c++){
                    ss.insert(grid[r][c]);
                }
            }
            if(ss.size()==1){
              //  ans[i][j]==0;
                continue;
            }
            int minabsdiff = INT_MAX;
            auto prev = ss.begin();
            auto curr = next(prev);
            while(curr != ss.end()){
                minabsdiff = min(minabsdiff ,*curr - *prev );
                prev = curr;
                curr++;
            }
            ans[i][j]=minabsdiff; 
         }
        }
        return ans;
    }
};