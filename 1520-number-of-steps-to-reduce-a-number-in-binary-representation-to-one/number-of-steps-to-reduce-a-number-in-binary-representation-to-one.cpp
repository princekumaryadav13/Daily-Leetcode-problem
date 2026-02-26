class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        // Traverse from right to left (ignore first bit)
        for (int i = s.size() - 1; i > 0; i--) {
            
            int bit = (s[i] - '0') + carry;

            // If even
            if (bit % 2 == 0) {
                steps += 1;  // divide by 2
            } 
            else {
                steps += 2;  // add 1 + divide by 2
                carry = 1;
            }
        }

        // If carry remains at MSB
        return steps + carry;
    }
};