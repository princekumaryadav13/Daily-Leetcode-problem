class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

       set<int>st;
       for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
       } 
       int count=1;
       int maxi =0;
       int prev = INT_MIN;
       for(auto it:st){
           if(prev +1 == it){
            count++;
           
           }
           else{
            count =1;
           }
            prev = it;
           maxi = max(maxi,count);
       }
       return maxi;
    }
};