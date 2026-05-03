class Solution {
public:
    bool isprime(int num){
    if(num <= 1) return false;   // 🔥 important
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
    int rev(int num){
        int ans =0;
        while(num>0){
            ans = ans*10 + num%10;
            num /=10;
        }
        return ans;
    }
    int sumOfPrimesInRange(int n) {
        int r = rev(n);
        int sum=0;
        if(n>=r){
          for(int i=r;i<=n;i++){
            if(isprime(i) ){
                sum += i;
            }
          }
        }
       if(r>n){
            for(int i=n;i<=r;i++){
            if(isprime(i)){
                sum += i;
            }
          }
        }
        return sum;
    }
};