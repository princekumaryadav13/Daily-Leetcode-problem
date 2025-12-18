class Solution {
public:
    typedef long long ll;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
       int n= prices.size();

       ll actualprofit =0;
       vector<ll>profit(n);

       for(int i=0;i<n;i++){
        profit[i]= (ll)strategy[i]*prices[i];
        actualprofit += profit[i];

       }
       ll originalwindowprofit =0;
       ll modifiedwindowprofit = 0;
       ll maxgain = 0;

       int i=0,j=0;

       while(j<n){
        originalwindowprofit += profit[j];

        if(j-i+1 > k/2){
            modifiedwindowprofit += prices[j];
        }
        if(j-i+1 >k){
            originalwindowprofit -= profit[i];
            modifiedwindowprofit -= prices[i+k/2];
            i++;
        }
        if(j-i+1 == k){
            maxgain = max(maxgain , modifiedwindowprofit - originalwindowprofit);
        }
        j++;
       } 
       return actualprofit + maxgain;
    }
};