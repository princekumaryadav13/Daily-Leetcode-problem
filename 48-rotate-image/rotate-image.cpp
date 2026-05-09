class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       
       int r=matrix.size();
       int c=matrix[0].size();
       vector<vector<int>>mat(r,vector<int>(c,0));

       for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            mat[i][j] = matrix[c-j-1][i];
        }
       } 
       matrix = mat;
    }
};