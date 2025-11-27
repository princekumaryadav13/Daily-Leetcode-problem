class Solution {
public:
    int kadanemax(vector<int>&nums,int n){
        int sum = nums[0];
        int maxsum = nums[0];

        for(int i=1;i<n;i++){
            sum = max(nums[i],sum+nums[i]);
            maxsum = max(maxsum , sum);
        }
        return maxsum;
    }
    int kadanemin(vector<int>&nums,int n){
        int sum = nums[0];
        int minsum = nums[0];

        for(int i=1;i<n;i++){
            sum = min(nums[i],sum+nums[i]);
            minsum = min(minsum , sum);
        }
        return minsum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
       int n= nums.size();
       //1
       int sum = accumulate(nums.begin(),nums.end(),0);
       //2
       int minsum = kadanemin(nums,n);

       int maxsum = kadanemax(nums,n);

       int circular_sum = sum - minsum;

       if(maxsum>0){
        return max(maxsum ,circular_sum);
       }
       return maxsum;
    }
};