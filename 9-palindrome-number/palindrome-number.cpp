class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int y = x;
       long long  rr = y%10;
        y = y/10;
        while(y>0){
            rr = rr*10 + y%10 ;
            y = y/10;
        }
        return rr == x;
    }
};