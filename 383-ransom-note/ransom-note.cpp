class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<int,int>mp;
        for(auto c :m){
            mp[c]++;

        }
        for(auto c : r){
            mp[c]--;
            if(mp[c]<0)return false;
        }
        return true;
    }
};