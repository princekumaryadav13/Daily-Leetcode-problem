class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
       sort(arr.begin(),arr.end());
       int minum = INT_MAX;
       for(int i=1;i<arr.size();i++){
        int mini = (arr[i]-arr[i-1]);
         minum = min(minum,mini);
       } 
       vector<vector<int>>ans;
       for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]== minum){
            ans.push_back({arr[i-1],arr[i]});
        }
       }
       return ans;
    }
};