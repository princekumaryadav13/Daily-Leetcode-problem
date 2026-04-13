class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
       vector<int>ans;

       for(int i=0;i<s.size();i++){
        int count =INT_MAX;
        for(int j =0;j<s.size();j++){
            if(s[j]== c){
                count = min(count,abs(i-j));
            }
           
        }
        ans.push_back(count);
       } 
       return ans;
    }
};