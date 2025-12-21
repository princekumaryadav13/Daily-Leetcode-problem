class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int count = 0;

        vector<int>alreadysorted(rows,false);
     

        for (int c = 0; c < cols; c++) {
            bool deleted = false;
            for (int r = 0; r < rows-1; r++) {
                if (!alreadysorted[r] && strs[r][c] > strs[r + 1][c]) {
                    count++;
                    deleted = true;
                    break;
                }
                
            }
            if(deleted){
                continue;
            }
           for(int i=0;i<rows-1;i++){
            alreadysorted[i]=alreadysorted[i] | (strs[i][c]<strs[i+1][c]);
           }
        }
        return count;
    }
};