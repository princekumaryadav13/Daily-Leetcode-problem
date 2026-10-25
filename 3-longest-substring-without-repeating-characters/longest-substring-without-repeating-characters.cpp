class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        
        vector<int> st(256, 0);
        int left = 0;

        for (int i = 0; i < s.size(); i++) {
           
            st[s[i] ]++;
            while(st[s[i] ] > 1) {
                st[s[left] ]--;
                left++;
            }
            maxi = max(maxi, i - left + 1);
            
        }
        return maxi;
    }
};