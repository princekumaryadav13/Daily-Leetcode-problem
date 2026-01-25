class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==0) return 0;

       int diff=INT_MAX;
       sort(nums.begin(),nums.end());
       for(int i=0;(i+k-1)<nums.size();i++){
       
            diff = min(abs(nums[i+k-1]-nums[i]) , diff);
        
       } 
       return  diff ;
    }
};