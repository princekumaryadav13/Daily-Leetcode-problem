class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
      vector<int>ans;
       int xr=0;
      for(auto que : queries)  {
        int left = que[0];
        int right = que[1];
        if(left==right){
            ans.push_back(arr[left]);
        }
        else{
            xr = arr[left];
        while(left<right){
            
            xr = xr^arr[left+1];
           left++;
         }
         ans.push_back(xr);
        }
      }
      return ans;
    }
};