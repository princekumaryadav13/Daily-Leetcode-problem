class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(i+1 < n && nums[i] == nums[i+1] && nums[i] != 0) {
                ans.push_back(nums[i] * 2);
                i++;
            }
            else if(nums[i] != 0) {
                ans.push_back(nums[i]);
            }
        }

        while(ans.size() < n) {
            ans.push_back(0);
        }

        return ans;
    }
};