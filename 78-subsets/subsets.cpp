class Solution {
public:
    vector<vector<int>>ans;
    void check(vector<int>&nums,vector<int>temp,int i){
        if(i==nums.size()){
            ans.push_back(temp);
          return   ;
        }
       temp.push_back(nums[i]);
        check(nums,temp ,i+1);
        temp.pop_back();
        check(nums,temp,i+1);
        

       

    }
    vector<vector<int>> subsets(vector<int>& nums) {
       // vector<vector<int>>ans;
        vector<int>temp;
         check(nums,temp,0);
         return ans;
    }
};