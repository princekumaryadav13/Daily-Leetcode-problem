class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3)return 0;
           int ans =0;
          int n =arr.size();
        for(int i=1;i+1<arr.size();i++){
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
               int l = i;
              while(l > 0 && arr[l] > arr[l-1]) l--; 

              int r = i;
            while(r < n-1 && arr[r] > arr[r+1]) r++;

          int   length = r - l + 1;
               ans = max(length ,ans);
            }
        }
        return ans;
    }
};