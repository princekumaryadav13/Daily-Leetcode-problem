class Solution {
public:
     long long t[1001][501][3];

     long long solve(int i,int k,int ca,vector<int>& prices){
        if(i==prices.size()){
            if(ca==0) return 0;

            return INT_MIN;
        }
        if(t[i][k][ca] != INT_MIN){
            return t[i][k][ca];
        }
        long long take = INT_MIN;
        long long nottake;

        nottake = solve(i+1,k,ca,prices);

        if(k>0){
            if(ca==1){
               take = prices[i] + solve(i+1,k-1,0,prices);
            }
            else if(ca==2){
                take = -prices[i] + solve(i+1,k-1,0,prices);
            }
            else{
                take = max(-prices[i] + solve(i+1,k,1,prices),prices[i]+solve(i+1,k,2,prices));
            }
        }
        return t[i][k][ca] = max(take,nottake);
     }
    long long maximumProfit(vector<int>& prices, int k) {
        int n= prices.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                for(int l=0;l<3;l++){
                    t[i][j][l]=INT_MIN;
                }
            }
        }
        return solve(0,k,0,prices);
    }
};