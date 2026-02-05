class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            
                int a = ( nums[i])%n;
               
            
                int b = (i + a)%n;

                if(b<0) b +=n;
                ans.push_back(nums[b]);
            
        }
        return ans;
    }
};