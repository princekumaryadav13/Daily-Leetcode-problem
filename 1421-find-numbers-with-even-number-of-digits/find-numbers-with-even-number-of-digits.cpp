class Solution {
public:
    bool hasevendigit(int num ){
        int dcount =0;
        while(num){
          dcount++;
          num = num/10;

        }
        return (dcount%2)==0;
    }
    int findNumbers(vector<int>& nums) {
        int ecount =0;

        for(auto num : nums){
            if(to_string(num).size()%2==0){
                ecount++;
            }
        }
        return ecount;
    }
};