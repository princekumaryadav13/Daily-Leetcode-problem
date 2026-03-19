class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicate i
            
            int s = i + 1;
            int l = n - 1;
            while (s < l) {
                int sum = nums[i] + nums[s] + nums[l];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[s], nums[l]});
                    s++;
                    l--;

                    // skip duplicates
                    while (s < l && nums[s] == nums[s - 1])
                        s++;
                    while (s < l && nums[l] == nums[l + 1])
                        l--;
                } else if (sum < 0) {
                    s++;
                } else {
                    l--;
                }
            }
        }
        return ans;
    }
};