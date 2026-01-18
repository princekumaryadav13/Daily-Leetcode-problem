class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            unordered_set<char>mm;
            for(int j=i;j<s.size();j++){
                if(mm.find(s[j]) != mm.end()){
                    break;
                }
                mm.insert(s[j]);
            }
            res =max(res,(int)mm.size());
        }
        return res;
    }
};