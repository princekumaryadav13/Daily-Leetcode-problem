class Solution {
public:
    int findMin(vector<int>& nums) {
        vector<int>num=nums;
        sort(num.begin(),num.end());
        int j;
        for(int i=0;i<nums.size();i++){
            if(num[0]==nums[i]){
                j=i;
            }
        }
        return num[0];
    }
};