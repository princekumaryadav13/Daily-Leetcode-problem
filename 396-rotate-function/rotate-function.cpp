class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long sum =0,f0 =0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            f0 += (long)i * nums[i];

        }
        long ans = f0;
        long curr = f0;

        for(int k=1;k<n;k++){
            curr = curr + sum - (long )n * nums[n-k];
            ans = max(ans,curr);
        }
        
       return ans;
         
    }
};