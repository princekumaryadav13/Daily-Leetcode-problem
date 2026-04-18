
        

    class Solution {
public:
    set<vector<int>>ans;
    void check(vector<int>&nums,vector<int>temp,int i){
        if(i==nums.size()){
            sort(temp.begin(),temp.end());
            ans.insert(temp);
          return   ;
        }
       temp.push_back(nums[i]);
        check(nums,temp ,i+1);
        temp.pop_back();
        check(nums,temp,i+1);
        

       

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       // vector<vector<int>>ans;
        vector<int>temp;
         check(nums,temp,0);
         return vector<vector<int>>(ans.begin(),ans.end());
    }
};


