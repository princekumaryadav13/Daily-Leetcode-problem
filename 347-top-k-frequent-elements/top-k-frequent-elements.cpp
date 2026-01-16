class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {

            mp[nums[i]]++;
        }
       priority_queue<pair<int,int>> mh;

        for (auto num : mp) {
           mh.push({num.second, num.first});

        }
        while (k > 0) {
           
          auto [freq, val] = mh.top();

            ans.push_back(val);
            mh.pop();
            k--;
        }

        return ans;
    }
};
