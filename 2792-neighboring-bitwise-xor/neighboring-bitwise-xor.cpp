class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        
        //first check the original[0] =0;
        vector<int>original(n);
        original[0]=0;
        for(int i=0;i<n-1;i++){
            original[i+1]=original[i]^derived[i];

        }
        if((original[n-1]^0)==derived[n-1]) return true;

        //first check the original[0] =1;
        vector<int>ori(n);
        ori[0]=1;
        for(int i=0;i<n-1;i++){
            ori[i+1]=ori[i]^derived[i];
        }
        if((ori[n-1]^1)==derived[n-1]) return true;

        return false;
    }
};