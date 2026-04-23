class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>ans;

        for(int i=0;i<nums1.size();i++){
           int a = nums1[i][0];
           int b = nums1[i][1];
           bool found = false;
           for(int j=0;j<nums2.size();j++){
            int c = nums2[j][0];
            int d = nums2[j][1];
            if(a==c){
                ans.push_back({a,b+d});
                found = true;
            }
           }
           if(!found)ans.push_back({a,b});
        }
        for(int i=0;i<nums2.size();i++){
           int a = nums2[i][0];
           int b = nums2[i][1];
           bool found = false;
           for(int j=0;j<nums1.size();j++){
            int c = nums1[j][0];
            int d = nums1[j][1];
            if(a==c){
                ans.push_back({a,b+d});
                found = true;
            }
           }
           if(!found)ans.push_back({a,b});
        }
       sort(ans.begin(), ans.end());
ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};