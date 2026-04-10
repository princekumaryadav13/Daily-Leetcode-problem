class Solution {
public:
    vector<int> evenOddBit(int n) {
        string s ="";
        while(n>0){
            s = s+char('0'+(n%2));
            n = n/2;
        }
        int e =0,o=0;
        for(int i=0;i<s.size();i++){
           if(((i) % 2 == 0) && s[i] == '1'){
            e++;
           }
           if(((i)%2!=0)&& s[i]=='1'){
            o++;
           }
        }
        vector<int>arr;
        arr.push_back(e);
        arr.push_back(o);
        return arr;
    }
};