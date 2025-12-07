class Solution {
public:
    int countOdds(int low, int high) {
      int odd = 0;
        for (int num = low; num <= high; num++) {
            if (num%2!=0) {
                odd++;
            }
        }
        return odd;  
    }
};