class Solution {
public:
    int hammingWeight(int ans) {
        int count=0;


      while(ans > 0) {
            int digit = ans % 2;
            if(digit==1)count++;

            ans /= 2;
        }  
        return count; 
    }
};