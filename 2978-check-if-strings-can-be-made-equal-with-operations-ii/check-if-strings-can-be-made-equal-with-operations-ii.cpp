class Solution {
public:
    bool checkStrings(string s1, string s2) {
        

        int freq1[2][26] = {}, freq2[2][26] = {};
        
        for (int i = 0; i < s1.size(); i++) {
            freq1[i % 2][s1[i] - 'a']++;
            freq2[i % 2][s2[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (freq1[0][i] != freq2[0][i]) return false;
            if (freq1[1][i] != freq2[1][i]) return false;
        }
        
        return true;
    }
};
   