class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int count=0;
        for(int i=0;i<op.size();i++){
            if(op[i]=="--X" || op[i]=="X--"){
                count--;
            }
            else{
                count++;
            }
        }
       return count;
    }
};