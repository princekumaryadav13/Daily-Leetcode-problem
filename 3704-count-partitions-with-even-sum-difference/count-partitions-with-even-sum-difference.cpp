class Solution {
public:
    int countPartitions(vector<int>& nums) {
       int sum = accumulate(nums.begin(),nums.end(),0);
       vector<int>ans;
       ans.push_back(nums[0]);
       for(int i=1;i<nums.size();i++){
          ans.push_back(ans.back()+nums[i]);
       } 
       int count =0;
       for(auto it : ans){
        
        if((sum-it!=0)&&((sum-it)-it)%2==0)  count++;
       }
       return count;
    }
};