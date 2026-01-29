class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       vector<vector<int>>mat=matrix;
       int r=mat.size();
       int c=mat[0].size();
       for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            matrix[i][j]= mat[c-j-1][i];
        }
       } 
    }
};