class Solution {
public:
    bool isPalindrome(string s) {
        string ss;

        for (int i = 0; i < s.size(); i++) {
            if (isalnum((unsigned char)s[i])) {
                ss.push_back(tolower((unsigned char)s[i]));
            }
        }

        string sss = ss;
        reverse(sss.begin(), sss.end());

        return ss == sss;
    }
};
