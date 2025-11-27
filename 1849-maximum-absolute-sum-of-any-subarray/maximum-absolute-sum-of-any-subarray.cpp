class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefix = 0;
        int maxPrefix = 0;
        int minPrefix = 0;

        for(auto x : nums){
           prefix += x;
            maxPrefix = max(maxPrefix, prefix);
            minPrefix = min(minPrefix, prefix);
        }
        
        return maxPrefix - minPrefix;
    }
};