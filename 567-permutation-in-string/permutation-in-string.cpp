class Solution {
public:
    bool checkInclusion(string s, string p) {

        int k = s.size();
        int n = p.size();

        if (k > n)
            return false;

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        // TODO 1: Build frequency arrays for p
        // and the first window of s
        for (int i = 0; i < k; i++) {
            need[s[i] - 'a']++;
            window[p[i] - 'a']++;
        }

        // TODO 2: Check the first window
        // If frequencies match, store index 0
        if (need == window) {
            return true;
        }

        // TODO 3: Slide the window
        for (int right = k; right < n; right++) {
            // Remove outgoing character
            window[p[right - k] - 'a']--;

            // Add incoming character
            window[p[right] - 'a']++;

                // If frequencies match, store
                if (window == need) {
                return true;
            }
            // the starting index of this window
        }

        return false;
    }
};