class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n= code.size();
       vector<int>ans(n);
       if(k>0){
      
        
        for(int i=0;i<code.size();i++){
           int sum =0;
           int j=i;
           int x = k;
           while(x>0){
            j++;
            sum += code[j%n];
            x--;
           }
           ans[i] = sum;
        }
       }
       if(k==0){
        for(int i=0;i<n;i++){
            ans[i]=0;
        }
       } 
       if(k<0){
        
        for(int i=0;i<n;i++){
            int sum =0;
            int j = i;
            int x =abs(k);
            while(x>0){
                j--;
                sum += code[(j+n)%n];
                x--;
            }
            ans[i]=sum;
        }
       }
       return ans;
    }
};