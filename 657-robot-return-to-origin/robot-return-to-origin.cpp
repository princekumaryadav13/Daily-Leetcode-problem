class Solution {
public:
    bool judgeCircle(string moves) {
        int r =0;
        int u =0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U'){
                u++;
            }
            else if(moves[i]=='D'){
                u--;
            }
           else if(moves[i]=='R'){
                r++;
            }
           else{
            r--;
           }
        }
        if(r==0 && u ==0 )return true;
        return false;
    }
};