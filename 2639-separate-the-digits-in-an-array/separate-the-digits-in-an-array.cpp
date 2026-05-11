class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
       vector<int>ans;
       for(auto it : nums){
        vector<int>rr;
        while(it>0){
            int a =it%10;
            rr.push_back(a);
            it /=10;
            
        }
        reverse(rr.begin(),rr.end());
        for(auto b : rr){
            ans.push_back(b);
        }
       } 
       return ans;
    }
};