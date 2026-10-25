
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi = 0;
        int left = 0;
        int mf = 0;

        vector<int> st(26, 0);

        for (int right = 0; right < s.size(); right++) {

            // 1. Add the current character
            st[s[right] - 'A']++;

            // 2. Update maximum frequency
            mf = max(mf, st[s[right] - 'A']);

            // 3. Shrink while the window is invalid
            while ((right - left + 1) - mf > k) {
                st[s[left] - 'A']--;
                left++;
            }

            // 4. Update the maximum valid window length
            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};
