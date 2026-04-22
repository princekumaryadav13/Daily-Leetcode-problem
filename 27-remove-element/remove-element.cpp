class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int count=0;
      int n = nums.size();
      vector<int>num;
      int i=0;
      while(i<nums.size()){
        if(nums[i]==val){
            count++;
           i++;
        }
        else{
            num.push_back(nums[i]);
            i++;
        }
        
       
      }  
      nums=num;
      return nums.size();
    }
};