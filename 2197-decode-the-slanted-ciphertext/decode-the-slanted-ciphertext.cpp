class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ans="";
        int n = encodedText.size();
        int col = n/rows;
        for(int i=0;i<col;i++){
            for(int j =i ;j<n ; j+=col+1){
                ans.push_back(encodedText[j]);
            }
        }
        while(!ans.empty() && ans.back()==' '){
            ans.pop_back();
        }
        return ans;
    }
};