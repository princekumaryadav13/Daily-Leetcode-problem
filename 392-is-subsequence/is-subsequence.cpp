class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size();
          int k =-1;
        for( int i=0;i<s.size();i++){
             
              bool found = true;;
            for(int j=k+1;j<n;j++){
                 if(s[i]==t[j]){
                    k=j;
                   found = false;
                    break;
                 }
            }
            if(found) return false;
        }
        return true;
    }
};  