class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size();
        int n = mat[0].size();
        int k=0;
        vector<vector<int>> temp(n, vector<int>(n));
        while(k<4){
       
       for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            temp[j][n-i-1] = mat[i][j];
        }
         }
         if(temp == target){
            return true;
         }
         k++;
         mat = temp;
        }
        return false;
    }
};