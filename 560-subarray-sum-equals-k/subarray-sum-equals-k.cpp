class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total=0; 
        int prefixsum =0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefixsum += nums[i];
            if(mp.find(prefixsum-k)!=mp.end()){
                total += mp[prefixsum-k];
                mp[prefixsum]++;
            }
            else{
                mp[prefixsum]++;
            }
        }
        return total;
    }
};