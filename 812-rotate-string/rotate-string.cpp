class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        int n= s.size();
         
        vector<int>st;
        for(int i=0;i<s.size();i++){
            if(s[0]==goal[i]){
               st.push_back(i);
            }
        }
        bool found = false;
        for(auto k : st){
        for(int i=0;i<n;i++){
            if(s[i]==goal[(i+k)%n]){
                if(i==n-1){
              found = true;
              break;
                }
                
            }
            else{
                break;
            }
        
         }
        }
        return found;
    }
};