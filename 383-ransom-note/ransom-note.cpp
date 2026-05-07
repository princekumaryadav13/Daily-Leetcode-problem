class Solution {
public:
    bool canConstruct(string r, string m) {
       vector<int>v(26,0);
        for(auto c :m){
            v[c-'a']++;

        }
        for(auto c : r){
           v[c-'a']--;
            if(v[c-'a']<0)return false;
        }
        return true;
    }
};