class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto aa :mp){
            ans.push_back(aa.second);
           // for(auto aaa :aa.second ){
           //     ans.push_back(aaa);
          //  }
        }
        return ans;
    }
};