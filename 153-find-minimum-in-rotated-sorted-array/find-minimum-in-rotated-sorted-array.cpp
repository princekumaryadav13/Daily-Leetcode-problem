class Solution {
public:
    int findMin(vector<int>& nums) {
        vector<int>num=nums;
        sort(num.begin(),num.end());
       
        return num[0];
    }
};