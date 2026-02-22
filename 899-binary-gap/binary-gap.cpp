class Solution {
public:
    int binaryGap(int n) {
        vector<int> ans;

        // Convert to binary
        while (n > 0) {
            int a = n % 2;
            n /= 2;
            ans.push_back(a);
        }

        reverse(ans.begin(), ans.end());

        int maxcount = 0;
        int lastIndex = -1;

        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 1) {
                if (lastIndex != -1) {
                    maxcount = max(maxcount, i - lastIndex);
                }
                lastIndex = i;
            }
        }

        return maxcount;
    }
};