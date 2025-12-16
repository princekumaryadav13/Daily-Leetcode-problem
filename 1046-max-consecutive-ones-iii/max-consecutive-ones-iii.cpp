class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int n = nums.size();
      int countzero =0;
      int maxi =0;
      int i=0,j=0;  
      while(j<n){
        if(nums[j]==0){
            countzero++;
        }
        while(countzero >k){
            if(nums[i]==0){
                countzero--;
            }
            i++;
        }
        maxi= max(maxi,j-i+1);
        j++;
      }  
      return maxi;
    }
};