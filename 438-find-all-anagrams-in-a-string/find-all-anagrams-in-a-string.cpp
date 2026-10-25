class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n = s.size();
        int k = p.size();

        vector<int> ans;

        if (k > n)
            return ans;

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        // TODO 1: Build frequency arrays for p
        // and the first window of s
        for (int i = 0; i < k; i++) {
            need[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }

        // TODO 2: Check the first window
        // If frequencies match, store index 0
        if (need == window) {
            ans.push_back(0);
        }

        // TODO 3: Slide the window
        for (int right = k; right < n; right++) {
            // Remove outgoing character
            window[s[right - k] - 'a']--;

            // Add incoming character
            window[s[right] - 'a']++;

            // If frequencies match, store
            if (window == need) {
                ans.push_back(right - k + 1);
            }
            // the starting index of this window
        }

        return ans;
    }
};