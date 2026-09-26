class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        string ans = "";

        map<string, string> mp;

        // Store knowledge in map
        for(auto x : knowledge) {
            mp[x[0]] = x[1];
        }

        for(int i = 0; i < s.size(); i++) {

            // If we find '('
            if(s[i] == '(') {

                string dup = "";

                i++;   // move after '('

                // Extract key until ')'
                while(s[i] != ')') {
                    dup += s[i];
                    i++;
                }

                // Find key in map
                auto it = mp.find(dup);

                if(it != mp.end()) {
                    ans += it->second;
                }
                else {
                    ans += '?';
                }
            }
            else {

                // Normal character
                ans += s[i];
            }
        }

        return ans;
    }
};