class Solution {
public:
    
    bool check1(string & code){
        if(code.empty()) return false;
        for(int i=0;i<code.size();i++){
           if(!(isalnum(code[i]) || code[i]=='_')){
            return false;
           }
        }
        return true;
    }
     bool check2(string & xyz){
        if((xyz == "electronics") || (xyz == "grocery") || (xyz == "pharmacy")|| (xyz == "restaurant") ){
            return true;
        }
        return false;
     }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
      unordered_map<string,int>mp={{"electronics",0},{ "grocery",1}, {"pharmacy",2} ,{"restaurant",3}};
                     
               
              
                
      
      vector<pair<int,string>>st;
        int n=code.size();
        for(int i=0;i<n;i++){
            if(check1(code[i]) && check2(businessLine[i]) && isActive[i]){
               st.push_back({mp[businessLine[i]] , code[i]}); 
            }
        }
       
        sort(st.begin(),st.end());
        vector<string>ans;
        for (auto &x : st) {
            
                ans.push_back(x.second);
            
        }
        return ans;
    }
};