class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans =0;

        for(int i=0;i<prices.size();i++){
            mini = min(prices[i],mini);
            int curr = prices[i]-mini ;
            if(curr>0){
                mini =prices[i];
                ans +=curr;
            }
        }
        return ans;
    }
};