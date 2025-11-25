class Solution {
public:
    int largestCombination(vector<int>& candidates) {
          int maxcount = 0;
       
        for(int bitpos = 0;bitpos < 32; bitpos++){
             int count=0;
               for(int & num : candidates){
                if((num & (1 << bitpos))!= 0){
                    count++;
                }
                  maxcount = max(maxcount,count);
            }
           
        }
        return maxcount;
    }
};