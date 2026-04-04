class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        int n = encodedText.size();
        int col = n/rows;
        vector<vector<int>>mat(rows,vector<int>(col));
        int index =0 ;
        for(int i=0;i<rows;i++){
            for(int j =0 ;j<col ; j++){
                mat[i][j] =  encodedText[index++];
            }
        }
        string ans="";
        for(int k =0;k<col;k++){
            int i =0;
            int j = k;
            while(i<rows && j<col){
                ans.push_back(mat[i][j]);
                i++;
                j++;
            }
        }
        while(!ans.empty() && ans.back()==' '){
            ans.pop_back();
        }
        return ans;
    }
};