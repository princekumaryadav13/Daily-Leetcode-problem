class Solution {
public:
    char findTheDifference(string s, string t) {
        int res=0;
        for(auto  a :s){
            res ^= a;
        }
        for( char b : t){
            res ^= b;
        }
        return res;
    }
};