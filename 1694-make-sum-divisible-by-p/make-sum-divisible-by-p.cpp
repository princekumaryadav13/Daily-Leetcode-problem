class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long total = 0;
        for(int x : nums) total += x;

        int need = total % p;
        if(need == 0) return 0;

        unordered_map<int, int> last;
        last[0] = -1;

        long prefix = 0;
        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            int cur = prefix % p;

            int target = (cur - need + p) % p;
            if(last.count(target)){
                int len = i - last[target];
                ans = min(ans, len);
            }

            last[cur] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};
