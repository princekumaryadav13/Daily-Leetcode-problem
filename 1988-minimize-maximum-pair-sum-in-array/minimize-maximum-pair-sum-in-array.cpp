class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n= nums.size();
        int l=n;
        vector<int>ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n/2;i++){
            int sum = nums[i]+nums[l-1];
            ans.push_back(sum);
            l--;
        }
        return *max_element(ans.begin(),ans.end());
         
    }
};