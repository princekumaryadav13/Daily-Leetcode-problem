class Solution {
public:
    int valid(vector<int>& nums, int k){
        if(k==0)return 0;
        unordered_map<int,int>mp;
        int left =0;
        int count =0;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            count += i-left+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
     
        return valid(nums,k)- valid(nums,k-1);
    }
};