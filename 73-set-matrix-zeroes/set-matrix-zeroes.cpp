class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n= matrix[0].size();

       vector<int>row(m,1);
       vector<int>col(n,1);

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                row[i]=0;
                col[j]=0;
                
            }
        }  
       }
       vector<vector<int>>ans(m,vector<int>(n,1));
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i]==0 || col[j]==0){
                ans[i][j]=0;
            }
            else{
                ans[i][j]=matrix[i][j];
            }
        }
        }
        matrix = ans;
    }
};