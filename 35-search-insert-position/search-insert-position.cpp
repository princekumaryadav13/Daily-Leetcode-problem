class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0, l = nums.size()-1;
       int ans = nums.size() ;
        while(s<=l){
            int mid = s +(l-s)/2;

            if(nums[mid]==target){
               ans = mid;
               break;
            }
            else if(nums[mid]<target){
                s = mid +1;
            }else{
                ans = mid;
                l = mid-1;
            }
        }
        return ans;
    }
};