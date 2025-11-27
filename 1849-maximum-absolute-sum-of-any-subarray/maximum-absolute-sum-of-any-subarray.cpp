class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int maxsum = nums[0];
        int minsum = nums[0];

        int currsummax = nums[0];
        int currsummin = nums[0];
        for(int i=1;i<n;i++){
            //kadane algo for maxsum
           currsummax = max(nums[i],currsummax + nums[i]);
           maxsum = max(maxsum,currsummax);
           // kadane algo for min sum;
           currsummin = min(nums[i],currsummin + nums[i]);
           minsum = min(minsum,currsummin);
        }
        
        return max(maxsum  ,abs(minsum ));
    }
};