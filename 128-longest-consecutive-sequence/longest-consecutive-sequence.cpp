class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        sort(nums.begin(),nums.end());
        int countc=1;
        int count=1;

        for(int i=0;i<nums.size()-1;i++){
           if(nums[i]+1==nums[i+1]){
            countc++;
           }
           else{
            if(nums[i]!=nums[i+1]){
            countc=1;
            }
             
           }
           count =max(countc,count);
           
        }
        return count;
    }
};