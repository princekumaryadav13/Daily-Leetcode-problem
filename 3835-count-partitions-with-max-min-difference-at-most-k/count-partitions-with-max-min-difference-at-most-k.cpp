#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;

        // dp[i] = number of ways to partition prefix of length i (nums[0..i-1]).
        // dp[0] = 1 (empty prefix)
        vector<int> dp(n+1, 0);
        vector<int> pref(n+1, 0); // pref[i] = sum(dp[0..i]) mod MOD

        dp[0] = 1;
        pref[0] = 1;

        deque<int> maxdq; // store indices, decreasing values
        deque<int> mindq; // store indices, increasing values
        int l = 0; // leftmost allowed start index for current r

        for (int r = 0; r < n; ++r) {
            // add nums[r] to both deques
            while (!maxdq.empty() && nums[maxdq.back()] <= nums[r]) maxdq.pop_back();
            maxdq.push_back(r);
            while (!mindq.empty() && nums[mindq.back()] >= nums[r]) mindq.pop_back();
            mindq.push_back(r);

            // move left pointer while window [l..r] invalid
            while (l <= r) {
                int curMax = nums[maxdq.front()];
                int curMin = nums[mindq.front()];
                if (curMax - curMin <= k) break;

                // remove index l if it is at front of either deque
                if (!maxdq.empty() && maxdq.front() == l) maxdq.pop_front();
                if (!mindq.empty() && mindq.front() == l) mindq.pop_front();
                ++l;
            }

            // dp[r+1] = sum_{j = l..r} dp[j] = pref[r] - pref[l-1]
            int sumRange = pref[r];
            if (l - 1 >= 0) {
                sumRange = (sumRange - pref[l-1]) % MOD;
                if (sumRange < 0) sumRange += MOD;
            }
            dp[r+1] = sumRange;
            pref[r+1] = pref[r] + dp[r+1];
            if (pref[r+1] >= MOD) pref[r+1] -= MOD;
        }

        return dp[n];
    }
};
