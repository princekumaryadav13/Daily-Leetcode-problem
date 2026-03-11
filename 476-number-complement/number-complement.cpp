class Solution {
public:
    int findComplement(int num) {
       if(num ==0)return 1;

     long long   ans =0 ,mul =1 ,rem;
     while(num){
        rem = num%2;
        rem = rem^1;
        num /=2;
        ans = ans + rem*mul;
        mul = mul*2;
     }
     return ans;
    }
};