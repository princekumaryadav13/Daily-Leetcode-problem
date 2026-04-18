class Solution {
public:
     vector<vector<int>>ans;

     void check(vector<int>& candidates, int target , int sum , vector<int>temp,int i){
       if(sum == target){
        ans.push_back(temp);
        return ;
       }
       if(sum>target || i==candidates.size()){
        return ;
       }
        //not take 
        check(candidates,target,sum,temp,i+1);
        temp.push_back(candidates[i]);
       // sum = sum+candidates[i];
        check(candidates,target,sum+candidates[i],temp,i);
        temp.pop_back();
      //  sum = sum-candidates[i];
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        check(candidates,target,0,temp,0);
        return ans;
    }
};