class Solution {
public:
    int n;
     vector<string>res;
    bool isvalid(string str){
        if(str[0]=='0')return false;

        int val = stoi(str);
        if(val>255)return false;

        return true;
    }
    void backtrack(string& s,int i,int dots,string ipcurr){
        if(dots==4 && i==n){
            ipcurr.pop_back();
            res.push_back(ipcurr);
            return;
        }
        if(dots >4)return ;

        if(i+1 <=n){
            backtrack(s,i+1,dots+1,ipcurr +s.substr(i,1)+".");
        }
        if(i+2 <= n && isvalid(s.substr(i,2))){
            backtrack(s,i+2,dots+1,ipcurr+s.substr(i,2)+".");

        }
        if(i+3 <= n && isvalid(s.substr(i,3))){
            backtrack(s,i+3,dots+1,ipcurr+s.substr(i,3)+".");
            
        }
        
        
    }
    vector<string> restoreIpAddresses(string s) {
        
      n = s.length();
      if(n>12)return {};
      backtrack(s,0,0, "");
      return res;
    }
};