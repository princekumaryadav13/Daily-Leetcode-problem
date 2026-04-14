class Solution {
public:
     typedef long long ll;

   ll solve(int ri ,int fi ,vector<int>&robot ,vector<int>&pos,vector<vector<ll>>&t){
      if(ri>=robot.size()){
        return 0;
      }  
      if(fi >= pos.size()) return 1e12;
        if(t[ri][fi] !=-1)return t[ri][fi] ;
    ll take = abs(robot[ri]-pos[fi])+ solve(ri+1 , fi+1,robot ,pos,t);
    ll skip = solve(ri,fi+1,robot,pos,t);

      return t[ri][fi] = min(take ,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        
        vector<int>fact;
        int m = robot.size();
        for(int i=0;i<factory.size();i++){
            int limit = factory[i][1];
            int pos = factory[i][0];

            for(int j=0;j<limit;j++){
                fact.push_back(pos);
            }
        }
        int n = fact.size();
        vector<vector<ll>>t(m+1,vector<ll>(n+1,-1));
        return solve(0,0,robot,fact,t);
    }
};