class Solution {
public:
 long long rev(long long num){
    long long ans=0;
    while(num>0){
        ans = ans*10 + num%10;
       num = num/10;
    }
    return ans;
 }
    int mirrorDistance(int n) {

       return abs(n-rev(n)); 
    }
};