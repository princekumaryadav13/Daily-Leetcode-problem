class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int used = nums[0];
        int sum = nums[0];
        int count = 0;
        
        priority_queue<int,vector<int>, greater<int>>aa;
       // sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
           aa.push(nums[i]);
        }
         while (!aa.empty()){
            sum += aa.top();
            aa.pop();
            count++;
            if(count==2){
                break;
            }
        }
        return sum;
    }
};