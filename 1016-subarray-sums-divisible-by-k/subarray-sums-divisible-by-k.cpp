class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int> prefix(nums.size());
        int sum =0;

       for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum = ((sum % k) + k) % k;
            prefix[i] = sum;
        }
        mp[0]=1;
        int ans =0;
        for(int i=0;i<nums.size();i++){

            if(mp.count(prefix[i])){
              ans += mp[prefix[i]];
              mp[prefix[i]]++;
            }
            else{
                mp[prefix[i]]++;
            }
        }
        return ans;
    }
};