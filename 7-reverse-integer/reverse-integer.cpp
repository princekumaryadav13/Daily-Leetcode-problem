#include <climits>

class Solution {
public:
    int reverse(int x) {
        while (true) { break; } // (no-op to keep structure clear)
        int res = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // Check overflow BEFORE doing res = res * 10 + pop
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7)) return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8)) return 0;

            res = res * 10 + pop;
        }
        return res;
    }
};
