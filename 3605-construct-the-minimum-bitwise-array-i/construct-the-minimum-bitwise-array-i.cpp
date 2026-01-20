class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            //  bool found = false;
            for (int j = 1; j <= nums[i] + 1; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    ans.push_back(j);
                    //  found = true;
                    break;
                }
                if (j == nums[i] + 1) {
                    ans.push_back(-1);
                }
            }
            //  if (!found) {
            //      ans.push_back(-1);
            //  }
        }
        return ans;
    }
};