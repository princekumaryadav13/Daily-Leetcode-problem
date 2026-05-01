class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
     vector<int>s;
     vector<int>g;
     int count =0;
     int n= nums.size();

     for(int i=0;i<n;i++){
        if(nums[i]<pivot){
            s.push_back(nums[i]);
        }
        else if(nums[i]==pivot){
            count++;
        }
        else{
            g.push_back(nums[i]);
        }
     }
        while(count>0){
            s.push_back(pivot);
            count--;
        }
      for(auto i : g){
        s.push_back(i);
      }
      return s;
       
    }
};