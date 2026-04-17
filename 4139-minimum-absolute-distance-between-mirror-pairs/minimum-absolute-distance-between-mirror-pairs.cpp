class Solution {
public:
    int rev(int num){
        int ans=0 ;
        while(num>0){
            int a = num%10;
            ans = ans*10 +a;
            num = num/10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
           int x = nums[i];
           if(mp.count(x)){
            ans = min(ans,i-mp[x]);
           }
           mp[rev(x)] =i;
        } 
        return ans==INT_MAX ?-1 : ans ;
    }
};