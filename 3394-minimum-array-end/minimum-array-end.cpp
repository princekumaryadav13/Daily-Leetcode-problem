class Solution {
public:
    long long minEnd(int n, int x) {
        long long last = x;   // first element is x
        n--;                  // we already have 1 element

        while (n > 0) {
            last = x | (last + 1);  // next element
            n--;
        }

        return last;          // last element of the array
    }
};
