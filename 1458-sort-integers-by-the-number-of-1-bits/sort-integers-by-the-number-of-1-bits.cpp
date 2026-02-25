class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
      unordered_map<int, vector<int>> mp;

      for(int i=0;i<arr.size();i++){
        int a = __builtin_popcount(arr[i]);
        mp[a].push_back(arr[i]);
      }  
     // sort(mp.begin(),mp.end());
      vector<int>ans;
      vector<int>key;
      for( auto aa : mp) key.push_back(aa.first);
      sort(key.begin(),key.end());

      for(auto k : key){
        auto v = mp[k];
        sort(v.begin(),v.end());
        for(auto a : v) ans.push_back(a);
      }
       
      return ans;
    }
};