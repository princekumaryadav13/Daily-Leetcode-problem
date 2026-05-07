class Solution {
public:
    bool wordPattern(string pattern, string s) {

        map<char,string> st;
        map<string,char> mp;

        int k = 0;

        for(int i=0; i<pattern.size(); i++){

            if(k >= s.size()) {
                return false;
            }

            string sub = "";

            while(k < s.size() && s[k] != ' '){
                sub += s[k];
                k++;
            }

            k++;

            if(st.count(pattern[i])){

                if(st[pattern[i]] != sub){
                    return false;
                }
            }
            else{

                // reverse mapping check
                if(mp.count(sub)){
                    return false;
                }

                st[pattern[i]] = sub;
                mp[sub] = pattern[i];
            }
        }

        // extra words check
        if(k < s.size()){
            return false;
        }

        return true;
    }
};