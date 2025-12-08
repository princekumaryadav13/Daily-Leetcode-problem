class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                double hyp = sqrt((i * i) + (j * j));
                if (hyp == floor(hyp) && hyp <= n) {
                    count++;
                }
            }
        }
        return count;
    }
};