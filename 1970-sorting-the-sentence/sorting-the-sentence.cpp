class Solution {
public:
    string sortSentence(string s) {
      vector<string>ans(10);
      string temp ;
      int count =0, idx =0;

      while(idx<s.size()){
        if(s[idx]==' ' ||  s.size()-1 == idx){
            if(idx == s.size()-1){
                temp += s[idx];
            }
            int pos = temp[temp.size()-1]-'0';
            temp.pop_back();

            ans[pos] = temp;

            temp.clear();
            count++;
        }
        else{
            temp += s[idx];
        }
        idx++;
      }  
      for(int i=1;i<=count;i++){
        temp += ans[i];
        temp += " " ;
      }
      temp.pop_back();
      return temp;
    }
};