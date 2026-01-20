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
            if (i > j && candidates[i] == candidates[i-1]) continue;

            cc.push_back(candidates[i]);
            check(candidates,target,i+1,sum+candidates[i],cc);
           cc.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<int>cc;
        sort(candidates.begin(),candidates.end());
       
        check(candidates,target,0,0,cc);
      // 
      //  
      // unique(ans.begin(),ans.end());
        return ans;
    }
};