class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
       int rcount =1;
       int ccount=1;
        int count=1;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
       for(int i=0;i<hBars.size()-1;i++){
          if(hBars[i]+1==hBars[i+1]){
            count++;
          }
          else{
            
            count=1;
          }
          rcount = max(count,rcount);
       }
       count=1;
       
       for(int i=0;i<vBars.size()-1;i++){
          if(vBars[i]+1==vBars[i+1]){
            count++;
          }
          else{
            
            count=1;
          }
          ccount = max(count,ccount);
       }
      int side = min(rcount,ccount)+1;
      return side*side;
    }
};