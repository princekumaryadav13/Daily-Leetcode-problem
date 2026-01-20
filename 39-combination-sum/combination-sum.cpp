class Solution {
public:
    vector<vector<int>>ans;
    void check(vector<int>& candidates, int target,int j,int sum,vector<int>&cc){
        if(sum>target) return ;
        if(sum==target){
            ans.push_back(cc);
            return ;
        }
        for(int i=j;i<candidates.size();i++){
            cc.push_back(candidates[i]);
            check(candidates,target,i,sum+candidates[i],cc);
           cc.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>cc;
       
        check(candidates,target,0,0,cc);
      //  sort(ans.begin(),ans.end());
      //  unique(ans.begin(),ans.end());
        return ans;
    }
};